#ifndef DOWNLOADLIST_H
#define DOWNLOADLIST_H

#include <QObject>
#include <QFile>
#include <QStringListModel>

class DownloadList : public QStringListModel
{
public:
    void exportList(QFile *dest);
    void importList(QFile *src);

    void append(QString);
    int length();
    QString at(int idx);
    void clear();
private:
    QStringList list;
};

#endif // DOWNLOADLIST_H
