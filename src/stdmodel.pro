#-------------------------------------------------
#
# Project created by QtCreator 2016-12-10T12:55:54
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = stdmodel
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    phy/element.cpp \
    worker/worker.cpp \
    utils/importationdata.cpp \
    worker/elementpicker.cpp \
    utils/msghandler.cpp \
    phy/atomicorbital.cpp \
    phy/orbitallayers.cpp \
    phy/electron.cpp

HEADERS += \
    phy/element.h \
    utils/importationdata.h \
    worker/worker.h \
    include/definitions.h \
    worker/elementpicker.h \
    utils/msghandler.h \
    phy/atomicorbital.h \
    phy/orbitallayers.h \
    phy/electron.h
