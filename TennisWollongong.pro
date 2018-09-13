#-------------------------------------------------
#
# Project created by QtCreator 2018-08-17T13:47:36
#
#-------------------------------------------------

QT       += core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TennisWollongong
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    refine.cpp \
    player.cpp \
    addplayerdiag.cpp \
    editplayerdiag.cpp \
    datepick.cpp \
    familysearchdiag.cpp \
    addvenuediag.cpp \
    venue.cpp \
    editvenuediag.cpp

HEADERS += \
        mainwindow.h \
    refine.h \
    player.h \
    player.h \
    addplayerdiag.h \
    editplayerdiag.h \
    datepick.h \
    familysearchdiag.h \
    addvenuediag.h \
    venue.h \
    editvenuediag.h

FORMS += \
        mainwindow.ui \
    addplayerdiag.ui \
    editplayerdiag.ui \
    datepick.ui \
    refine.ui \
    familysearchdiag.ui \
    addvenuediag.ui \
    editvenuediag.ui

RESOURCES += \
    resources.qrc

