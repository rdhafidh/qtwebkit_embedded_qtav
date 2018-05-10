#-------------------------------------------------
#
# Project created by QtCreator 2015-05-26T09:02:18
#
#-------------------------------------------------

QT       += core gui webkitwidgets av avwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = webview1
TEMPLATE = app

CONFIG += console release
SOURCES += main.cpp\
        mainwindow.cpp \
    webview.cpp \
    pluginwebm.cpp playerwindow.cpp

HEADERS  += mainwindow.h \
    webview.h \
    mysum.h \
    pluginwebm.h playerwindow.h

FORMS    += mainwindow.ui
 

RESOURCES += \
    res.qrc
