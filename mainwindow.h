#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "downloader.h"
#include "settings.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void send_item(bool);                   //converts add_item pushButton click to string SIGNAL
    void clear_list(void);                  //clears download_list window
    void clear_item(void);                  //clears url input QLineEdit
    void get_working_directory(void);       //gets directory from QFileDialog
    void get_default_directory(void);       //gets directory from QFileDialog
    void about_this_application(void);      //information about current build
    void open_read_me_file(void);           //open README file

signals:
    void set_default_directory(QString);    //set default directory
    void set_download_directory(QString);   //set download directory
    void send_string(QString);              //string SIGNAL activated by send_item(bool)
                                            //sends url string to download_list in downloader
private:
    Ui::MainWindow *ui;
    void init_settings(Downloader *dl, Settings *st);   //initialize settings from file
};

#endif // MAINWINDOW_H
