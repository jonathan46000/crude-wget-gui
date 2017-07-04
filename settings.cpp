#include "settings.h"
#include <QObject>
#include <QString>
#include <QInputDialog>
#include <QDir>
#include <QCoreApplication>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

Settings::Settings(QObject *parent) : QObject(parent), default_directory("") {
    settings_directory = QCoreApplication::applicationDirPath();
    settings_file = settings_directory + "/settings.dat";
    QFile file(settings_file);
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        file.close();
        if(!file.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox message_box;
            message_box.critical(0,"Error","Can not open settings file!");
            message_box.setFixedSize(500,200);
            return;
        }
        QTextStream out(&file);
        out << default_directory;
        file.flush();
        file.close();
    }
    else {
        QTextStream in(&file);
        default_directory = in.readAll();
        file.close();
    }
}

void Settings::set_default_directory(QString in_string) {
    default_directory = in_string;
    QFile file(settings_file);
    //this will need to be moved to a destructor at some point that writes all settings to file
    if(!file.open(QFile::WriteOnly | QFile::Truncate | QFile::Text)) {
        QMessageBox message_box;
        message_box.critical(0,"Error","Can not open settings file!");
        message_box.setFixedSize(500,200);
        return;
    }
    QTextStream out(&file);
    out << default_directory;
    file.flush();
    file.close();
}

QString Settings::get_default_directory(void) {
    return default_directory;
}

