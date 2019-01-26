#-------------------------------------------------
#
# Project created by QtCreator 2019-01-14T12:55:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET              = ComicReader
TEMPLATE            = app

include(./../../Path.pri)

win32:RC_FILE       = other/main.rc

INCLUDEPATH         += $$PWD

SOURCES             += main.cpp \
    PixmapDelegate.cpp \
    PixFileSystemModel.cpp \
    MainWindow.cpp
SOURCES             +=

HEADERS             += \
    PixmapDelegate.h \
    PixFileSystemModel.h \
    MainWindow.h

FORMS               += \
    MainWindow.ui

RESOURCES           += other/qss.qrc
RESOURCES           += other/main.qrc
