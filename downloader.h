#ifndef DOWNLOADER_H
#define DOWNLOADER_H
#include <QList>
#include <QObject>

#include "downloadlist.h"

class Downloader : public QObject
{
    Q_OBJECT

private:

    DownloadList download_list;           //list of urls to download
    QStringList arguments;                  //argument list for wget
    QString in_string;                      //url input string
    QString passwd;                         //password
    QString uname;                          //user name
    QString directory;                      //download directory
    QString uname_flag = "--user";          //wget username flag
    QString passwd_flag = "--password";     //wget password flag
    QString dir_flag = "-P";                //wget directory flag
    void download_at_index(int index);      //function that calls wget for url on list
    int is_valid(QString str);              //checks arguments for malicious input
    int is_valid_directory(QString str);    //checks valid directory

public:

    explicit Downloader(QObject *parent = 0);
    DownloadList* get_download_list();

signals:

    void send_output_string(QString);       //places string in list of urls to download
    void ret_error(QString);                //for future use
    void clear_list_window(void);           //clears the list of urls to download
    void clear_address(void);               //clears the url input string

public slots:

    void set_input(QString);                //adds input url to list
    void set_uname(QString);                //sets uname member
    void set_passwd(QString);               //sets password member
    void set_directory(QString);            //sets download directory member
    void download_all(void);                //downloads all items on list

};

#endif // DOWNLOADER_H
