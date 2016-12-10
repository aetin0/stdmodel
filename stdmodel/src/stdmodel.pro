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
    utils/importationdata.cpp

HEADERS += \
    phy/element.h \
    utils/importationdata.h \
    worker/worker.h \
    include/definitions.h
