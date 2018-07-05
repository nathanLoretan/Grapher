#-------------------------------------------------
#
# Project created by QtCreator 2016-05-18T10:53:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Grapher
TEMPLATE = app

include(view.pri)
include(model.pri)
include(observer.pri)
include(controler.pri)

SOURCES +=  main.cpp\
            factory.cpp\
            qcustomplot/qcustomplot.cpp \

HEADERS +=  factory.h\
            style.h\
            qcustomplot/qcustomplot.h \

FORMS    +=

DISTFILES += \
            model.pri\
            view.pri\
            controler.pri\
            observer.pri
