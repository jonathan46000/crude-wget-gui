#ifndef DOWNLOADER_H
#define DOWNLOADER_H
#include <QList>
#include <QObject>

class Downloader : public QObject
{
    Q_OBJECT

private:

    QList <QString>download_list;
    QString in_string;
    QString out_string;
    QString passwd;
    QString uname;
    QString command = "wget ";
    QString uname_flag = "--user ";
    QString passwd_flag = " --password ";
    void download_at_index(int index);
    int is_secure(QString str);

public:

    explicit Downloader(QObject *parent = 0);

signals:

    void send_output_string(QString);
    void ret_error(QString);
    void clear_list_window(void);

public slots:

    void set_input(QString);
    void set_uname(QString);
    void set_passwd(QString);
    void download_all(void);

};

#endif // DOWNLOADER_H
