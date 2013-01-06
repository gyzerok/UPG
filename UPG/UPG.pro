#-------------------------------------------------
#
# Project created by QtCreator 2013-01-06T19:39:59
#
#-------------------------------------------------
TARGET = UPG

QT += core network
QT -= gui

TEMPLATE = app
CONFIG   += console
CONFIG   -= app_bundle

SOURCES += main.cpp \
    App.cpp \
    QServerSide.cpp \
    QParser.cpp \
    QController.cpp \
    GameActions.cpp \
    ServiceActions.cpp

HEADERS += \
    App.h \
    QServerSide.h \
    QParser.h \
    QController.h \
    GameActions.h \
    ServiceActions.h