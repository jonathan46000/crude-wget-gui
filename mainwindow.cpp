#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "downloader.h"
#include <QDir>
#include <QFileDialog>

/**************************************************************************************************
 * MAINWINDOW CONSTRUCTOR[CONTAINS SIGNAL/SLOT CONNECTIONS]
 *************************************************************************************************/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pword->setEchoMode(QLineEdit::Password);

    Downloader *downloader = new Downloader();

    //exit program
    MainWindow::connect(ui->actionExit,SIGNAL(triggered()),
                        this,SLOT(close()));

    //connect add_item button to send_string SIGNAL
    MainWindow::connect(ui->add_item,SIGNAL(clicked(bool)),
                        this,SLOT(send_item(bool)));

    //send_string SIGNAL adds item to download_list
    MainWindow::connect(this,SIGNAL(send_string(QString)),
                        downloader,SLOT(set_input(QString)));

    //adds item to the list window
    MainWindow::connect(downloader, SIGNAL(send_output_string(QString)),
                        ui->item_list,SLOT(appendPlainText(QString)));

    //updates uname variable when username text is changed
    MainWindow::connect(ui->uname,SIGNAL(textChanged(QString)),
                        downloader,SLOT(set_uname(QString)));

    //updates passwd variable when password text is changed
    MainWindow::connect(ui->pword,SIGNAL(textChanged(QString)),
                        downloader,SLOT(set_passwd(QString)));

    //downloads all items in the download_list
    MainWindow::connect(ui->download_list,SIGNAL(clicked()),
                        downloader,SLOT(download_all()));

    //clears the items in the list window
    MainWindow::connect(downloader,SIGNAL(clear_list_window()),
                        this,SLOT(clear_list()));

    //clears the url input when url is added to list
    MainWindow::connect(downloader,SIGNAL(clear_address()),
                        this,SLOT(clear_item()));

    //get path to download to
    MainWindow::connect(ui->actionDownload_Path,SIGNAL(triggered()),
                        this,SLOT(get_working_directory()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**************************************************************************************************
 * MAINWINDOW SLOTS
 *************************************************************************************************/

//opens dialog to set download path
void MainWindow::get_working_directory(void) {
    working_directory = QFileDialog::getExistingDirectory(this, tr("Select folder to save downloads"),
                                                 "/home",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);
    QDir::setCurrent(working_directory);
}

//sends string to be added to download_list
void MainWindow::send_item(bool) {
    send_string(ui->download_address->text());
}

//clears the list window
void MainWindow::clear_list() {
    ui->item_list->clear();
}

//clears the url input line
void MainWindow::clear_item() {
    ui->download_address->clear();
}
