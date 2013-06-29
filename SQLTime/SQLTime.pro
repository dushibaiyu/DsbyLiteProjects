#-------------------------------------------------
#
# Project created by QtCreator 2013-05-08T11:11:02
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SQLTime
TEMPLATE = app
CONFIG += C++11


SOURCES += main.cpp\
        mainwindow.cpp \
    singin.cpp \
    dbclass.cpp \
    setcheck.cpp \
    setlitedb.cpp \
    aeshelper.cpp \
    aes.cpp

HEADERS  += mainwindow.h \
    singin.h \
    dbclass.h \
    setcheck.h \
    setlitedb.h \
    aeshelper.h \
    aes.h

FORMS    += mainwindow.ui \
    singin.ui \
    setcheck.ui \
    setlitedb.ui

RESOURCES += \
    ico.qrc

win32:RC_FILE = main.rc

OTHER_FILES += \
    main.rc
