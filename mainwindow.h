#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

signals:
    void send_string(QString);              //string SIGNAL activated by send_item(bool)
                                            //sends url string to download_list in downloader
private:
    Ui::MainWindow *ui;
    QString working_directory;              //current working directory to download to
};                                          //should be moved to downloader eventually

#endif // MAINWINDOW_H
