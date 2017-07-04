#ifndef SETTINGS_H
#define SETTINGS_H
#include <QObject>
#include <QString>

class Settings : public QObject
{
    Q_OBJECT

private:
    QString default_directory;                          //default download directory
    QString settings_directory;                         //directory of settings file
    QString settings_file;                              //settings file

public:
    explicit Settings(QObject *parent = 0);             //constructor
    QString get_default_directory(void);                //return default directory

signals:

public slots:
    void set_default_directory(QString in_string);      //set default directory
};

#endif // SETTINGS_H
