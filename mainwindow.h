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
    void send_item(bool);
    void clear_list(void);
    void clear_item(void);

signals:
    void send_string(QString);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
