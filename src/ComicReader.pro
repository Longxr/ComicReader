#-------------------------------------------------
#
# Project created by QtCreator 2019-01-14T12:55:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET              = ComicReader
TEMPLATE            = app
MOC_DIR             = temp/moc
RCC_DIR             = temp/rcc
UI_DIR              = temp/ui
OBJECTS_DIR         = temp/obj
DESTDIR             = $$PWD/../bin
win32:RC_FILE       = other/main.rc

INCLUDEPATH         += $$PWD
CONFIG              += qt warn_off

SOURCES             += main.cpp \
    PixmapDelegate.cpp \
    PixFileSystemModel.cpp \
    PageSizeSetDlg.cpp \
    MainWindow.cpp
SOURCES             +=

HEADERS             += \
    PixmapDelegate.h \
    PixFileSystemModel.h \
    PageSizeSetDlg.h \
    MainWindow.h

FORMS               += \
    PageSizeSetDlg.ui \
    MainWindow.ui

RESOURCES           += other/qss.qrc
RESOURCES           += other/main.qrc
