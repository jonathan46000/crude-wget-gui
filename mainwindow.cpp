#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "downloader.h"
#include "settings.h"
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QCoreApplication>

/**************************************************************************************************
 * MAINWINDOW CONSTRUCTOR[CONTAINS SIGNAL/SLOT CONNECTIONS]
 *************************************************************************************************/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ensure passwords are not displayed on screen
    ui->pword->setEchoMode(QLineEdit::Password);

    //create objects to handle wget and settings
    this->dl = new Downloader();
    this->model = this->dl->get_download_list();
    this->ui->listView->setModel(this->model);

    Settings *settings = new Settings();

    //initialize settings from saved data
    MainWindow::init_settings(dl,settings);

    //exit program
    MainWindow::connect(ui->actionExit,SIGNAL(triggered()),
                        this,SLOT(close()));

    //connect add_item button to send_string SIGNAL
    MainWindow::connect(ui->add_item,SIGNAL(clicked(bool)),
                        this,SLOT(send_item(bool)));

    //send_string SIGNAL adds item to download_list
    MainWindow::connect(this,SIGNAL(send_string(QString)),
                        dl,SLOT(set_input(QString)));

    //adds item to the list window
    //MainWindow::connect(dl, SIGNAL(send_output_string(QString)),
    //                    ui->item_list,SLOT(appendPlainText(QString)));

    //updates uname variable when username text is changed
    MainWindow::connect(ui->uname,SIGNAL(textChanged(QString)),
                        dl,SLOT(set_uname(QString)));

    //updates passwd variable when password text is changed
    MainWindow::connect(ui->pword,SIGNAL(textChanged(QString)),
                        dl,SLOT(set_passwd(QString)));

    //downloads all items in the download_list
    MainWindow::connect(ui->download_list,SIGNAL(clicked()),
                        dl,SLOT(download_all()));

    //clears the items in the list window
    MainWindow::connect(dl,SIGNAL(clear_list_window()),
                        this,SLOT(clear_list()));

    //clears the url input when url is added to list
    MainWindow::connect(dl,SIGNAL(clear_address()),
                        this,SLOT(clear_item()));

    //about this application
    MainWindow::connect(ui->actionAbout,SIGNAL(triggered()),
                        this,SLOT(about_this_application()));

    //get path to download to
    MainWindow::connect(ui->actionDownload_Path,SIGNAL(triggered()),
                        this,SLOT(get_working_directory()));

    //get default path to download to
    MainWindow::connect(ui->actionDefault_path,SIGNAL(triggered()),
                        this,SLOT(get_default_directory()));

    //set download directory
    MainWindow::connect(this,SIGNAL(set_download_directory(QString)),
                        dl,SLOT(set_directory(QString)));

    //set default directory
    MainWindow::connect(this,SIGNAL(set_default_directory(QString)),
                        settings,SLOT(set_default_directory(QString)));

    //open help.txt in default text editor
    MainWindow::connect(ui->actionREADME,SIGNAL(triggered()),
                        this,SLOT(open_read_me_file()));

    //open import list dialog
    MainWindow::connect(ui->actionImport_Download_List,SIGNAL(triggered()),
                        this,SLOT(import_download_list()));

    //open export list dialog
    MainWindow::connect(ui->actionExport_Download_List,SIGNAL(triggered()),
                        this,SLOT(export_download_list()));



}


/*************************************************************************************************
 * MAINWINDOW PRIVATE FUNCTIONS
 * **********************************************************************************************/

//Destructor
MainWindow::~MainWindow()
{
    delete ui;
}

//Private mainwindow function to initialize settings
void MainWindow::init_settings(Downloader *dl, Settings *st) {
    if(!st->get_default_directory().isEmpty()) {
        dl->set_directory(st->get_default_directory());
    }
}

/**************************************************************************************************
 * MAINWINDOW SLOTS
 *************************************************************************************************/

//opens dialog to set download path
void MainWindow::get_working_directory(void) {
    QString working_directory = QFileDialog::getExistingDirectory(this, tr("Select folder to save downloads"),
                                                 "/home",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);
    set_download_directory(working_directory);
}

//opens dialog to set default download path
void MainWindow::get_default_directory(void) {
    QString default_dir = QFileDialog::getExistingDirectory(this, tr("Select folder to save downloads"),
                                                 "/home",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);
    set_default_directory(default_dir);
}

//information about the current build
void MainWindow::about_this_application(void) {
    QMessageBox message_box;
    message_box.about(0,"About",
                         "Build: 0.1.30\nAuthors: Jonathan Lundquist\n                &dotblank\nLicense: GPL V3\nBuild Date: July 6, 2017");
    message_box.setFixedSize(500,200);
}

//sends string to be added to download_list
void MainWindow::send_item(bool) {
    send_string(ui->download_address->text());
}

//clears the list window
void MainWindow::clear_list() {
    model->clear();
}

//clears the url input line
void MainWindow::clear_item() {
    ui->download_address->clear();
}

//open readme file with default application
void MainWindow::open_read_me_file() {
    QUrl path("file:////"  +QCoreApplication::applicationDirPath() + "/README.txt");
    QDesktopServices::openUrl(path);
}

//save list of items added to file
void MainWindow::export_download_list() {

    QUrl path = QFileDialog::getSaveFileUrl(this,tr("Save file to export"));
    if(path.isEmpty()) {
        return;
    }
    QFile exportFile(path.toLocalFile());
    dl->get_download_list()->export_list(&exportFile);
}

//import previously exported list from file
void MainWindow::import_download_list() {
    QUrl path = QFileDialog::getOpenFileUrl(this,tr("Choose file to import"));
    if(path.isEmpty()) {
        return;
    }
    QFile importFile(path.toLocalFile());
    dl->get_download_list()->import_list(&importFile);
}
