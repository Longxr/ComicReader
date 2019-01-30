#-------------------------------------------------
#
# Project created by QtCreator 2019-01-14T12:55:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET      = ComicReader
TEMPLATE    = app

include(./../../Path.pri)

INCLUDEPATH += $$PWD/../../Libraries
INCLUDEPATH += $$THIRD_DIR

LIBS += -L$${DESTDIR} -lQLib7z
LIBS += -L$${DESTDIR} -lquazip

win32: {
    RC_FILE = other/main.rc
}

SOURCES += \
    main.cpp \
    PixmapDelegate.cpp \
    PixFileSystemModel.cpp \
    MainWindow.cpp \
    ExtractArchiveManager.cpp \
    ComicDirModel.cpp

HEADERS += \
    PixmapDelegate.h \
    PixFileSystemModel.h \
    MainWindow.h \
    ExtractArchiveManager.h \
    ComicDirModel.h

FORMS += \
    MainWindow.ui

RESOURCES += other/qss.qrc
RESOURCES += other/main.qrc
