#include "downloader.h"
#include "stdio.h"
#include "stdlib.h"
#include <string>
#include <QProcess>
#include <QMessageBox>

Downloader::Downloader(QObject *parent) : QObject(parent)
{

}

void Downloader::set_input(QString input_string) {
    if(is_secure(input_string)) {
        in_string = input_string;
        download_list.append(in_string);
        send_output_string(in_string);
        clear_address();
    }
}

void Downloader::set_uname(QString input_string) {
    if(is_secure(input_string)) {
        uname = input_string;
    }
}

void Downloader::set_passwd(QString input_string) {
    if(is_secure(input_string)) {
        passwd = input_string;
    }
}

void Downloader::download_all(void) {
    int end = download_list.length();
    for(int x = 0; x < end; x++) {
        download_at_index(x);
    }
    clear_list_window();
}

void Downloader::download_at_index(int index) {
    QProcess * wget = new QProcess;
    wget->setProgram("wget");
    if(!uname.isEmpty()) {
        arguments.append(uname_flag);
        arguments.append(uname);
    }
    if(!passwd.isEmpty()) {
        arguments.append(passwd_flag);
        arguments.append(passwd);
    }
    arguments.append(download_list.at(index));
    wget->setArguments(arguments);
    wget->start();
    arguments.clear();
}

int Downloader::is_secure(QString str) {
    if(str.contains("sudo") ||
       str.contains("./") ||
       str.contains("/.") ||
       str.contains("..") ||
       str.contains("/bin") ||
       str.contains("/dev") ||
       str.contains("kernel.") ||
       str.contains("touch") ||
       str.contains("/tmp") ||
       str.contains("echo") ||
       str.contains("$ENV") ||
       str.contains("$HOME") ||
       str.contains("rm ") ||
       str.contains("%*.*s") ||
       str.contains("File:///") ||
       str.contains("System(") ||
       str.contains("TRUE") ||
       str.contains("FALSE") ||
       str.contains("NULL")) {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Input data is invalid!");
        messageBox.setFixedSize(500,200);
        return 0;
    }
    else {
        return 1;
    }
}

