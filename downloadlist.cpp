#include "downloadlist.h"
#include <QTextStream>

/**************************************************************************************************
 * DOWNLOADLIST PUBLIC FUNCTIONS
 *************************************************************************************************/

//export list of items to download to file
void DownloadList::export_list(QFile *dest) {
    dest->open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(dest);
    QStringList::iterator i;
    for(i = this->list.begin(); i != this->list.end(); ++i) {
        out << *i + "\n";
    }
    dest->close();
}

//import list from file
void DownloadList::import_list(QFile *src) {
    src->open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(src);
    while(!in.atEnd()) {
        this->append(in.readLine());
    }
    src->close();
}

//add new item to list
void DownloadList::append(QString s) {
    list.append(s);
    this->setStringList(list);
}

//return list length
int DownloadList::length() {
    return list.length();
}

//return string at index
QString DownloadList::at(int idx) {
    return list.at(idx);
}

//clear download list
void DownloadList::clear() {
    list.clear();
    this->setStringList(list);
}
