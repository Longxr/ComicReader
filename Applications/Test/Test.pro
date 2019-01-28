#-------------------------------------------------
#
# Project created by QtCreator 2019-01-28T10:03:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test
TEMPLATE = app

include(./../../Path.pri)

#INCLUDEPATH += ../../Libraries/quazip

#library
INCLUDEPATH += $$PWD/../../Libraries

SOURCES += main.cpp\
        MainWindow.cpp

HEADERS  += MainWindow.h

FORMS    += MainWindow.ui
