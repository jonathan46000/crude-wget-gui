#include "downloadlist.h"
#include <QTextStream>

void DownloadList::exportList(QFile *dest) {

    dest->open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream out(dest);

    QStringList::iterator i;
    for(i = this->list.begin(); i != this->list.end(); ++i) {
        out << *i + "\n";
    }
    dest->close();
}

void DownloadList::importList(QFile *src) {
    src->open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(src);

    while(!in.atEnd()) {

        this->append(in.readLine());
    }
    src->close();
}


void DownloadList::append(QString s) {
    list.append(s);
    this->setStringList(list);
}

int DownloadList::length() {
    return list.length();
}

QString DownloadList::at(int idx) {
    return list.at(idx);
}

void DownloadList::clear() {
    list.clear();
    this->setStringList(list);
}
