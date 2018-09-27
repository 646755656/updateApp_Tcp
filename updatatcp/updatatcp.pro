#-------------------------------------------------
#
# Project created by QtCreator 2018-05-26T11:45:24
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = updatatcp
TEMPLATE = app


SOURCES += main.cpp\
        frmmain.cpp \
    frmtcpserver.cpp \
    crc16.cpp

HEADERS  += frmmain.h \
    head.h \
    frmtcpserver.h \
    crc16.h

FORMS    += frmmain.ui \
    frmtcpserver.ui


include             ($$PWD/api/api.pri)

INCLUDEPATH         += $$PWD
INCLUDEPATH         += $$PWD/api

DISTFILES +=

RESOURCES += \
    source.qrc
