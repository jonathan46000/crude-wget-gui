#ifndef DOWNLOADLIST_H
#define DOWNLOADLIST_H

#include <QObject>
#include <QFile>
#include <QStringListModel>

class DownloadList : public QStringListModel
{
public:
    void export_list(QFile *dest);       //export list to file
    void import_list(QFile *src);        //import list from file
    void append(QString);               //add to list
    int length();                       //return list length
    QString at(int idx);                //get string at index
    void clear();                       //clear list
private:
    QStringList list;                   //list of items to download
};

#endif // DOWNLOADLIST_H
