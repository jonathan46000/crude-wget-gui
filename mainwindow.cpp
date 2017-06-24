#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "downloader.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pword->setEchoMode(QLineEdit::Password);

    Downloader *downloader = new Downloader();

    MainWindow::connect(ui->actionExit,SIGNAL(triggered()),
                        this,SLOT(close()));

    MainWindow::connect(ui->add_item,SIGNAL(clicked(bool)),
                        this,SLOT(send_item(bool)));

    MainWindow::connect(this,SIGNAL(send_string(QString)),
                        downloader,SLOT(set_input(QString)));

    MainWindow::connect(downloader, SIGNAL(send_output_string(QString)),
                        ui->item_list,SLOT(appendPlainText(QString)));

    MainWindow::connect(ui->uname,SIGNAL(textChanged(QString)),
                        downloader,SLOT(set_uname(QString)));

    MainWindow::connect(ui->pword,SIGNAL(textChanged(QString)),
                        downloader,SLOT(set_passwd(QString)));

    MainWindow::connect(ui->download_list,SIGNAL(clicked()),
                        downloader,SLOT(download_all()));

    MainWindow::connect(downloader,SIGNAL(clear_list_window()),
                        this,SLOT(clear_list()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::send_item(bool) {
    send_string(ui->download_address->text());
}

void MainWindow::clear_list() {
    ui->item_list->clear();
}
