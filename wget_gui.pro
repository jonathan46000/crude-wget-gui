#-------------------------------------------------
#
# Project created by QtCreator 2017-06-23T20:42:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = wget_gui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    downloader.cpp \
    settings.cpp \
    downloadlist.cpp

HEADERS  += mainwindow.h \
    downloader.h \
    settings.h \
    downloadlist.h

FORMS    += mainwindow.ui
