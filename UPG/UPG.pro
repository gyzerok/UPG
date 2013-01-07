#-------------------------------------------------
#
# Project created by QtCreator 2013-01-06T19:39:59
#
#-------------------------------------------------
TARGET = UPG

QT += core network xml
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
    ServiceActions.cpp \
    Registry.cpp \
    Game.cpp \
    User.cpp \
    Error.cpp

HEADERS += \
    App.h \
    QServerSide.h \
    QParser.h \
    QController.h \
    GameActions.h \
    ServiceActions.h \
    Action.h \
    Error.h \
    Registry.h \
    Game.h \
    User.h
