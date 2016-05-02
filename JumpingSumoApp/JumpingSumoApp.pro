#-------------------------------------------------
#
# Project created by QtCreator 2016-05-01T15:04:53
#
#-------------------------------------------------

QT       += core gui concurrent multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JumpingSumoApp
TEMPLATE = app
CCFLAG += std=c++14

INCLUDEPATH += ../lib/
INCLUDEPATH += /usr/local/Cellar/opencv/2.4.12_2/include
LIBS += -L/usr/local/Cellar/opencv/2.4.12_2/lib -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_video

SOURCES += main.cpp\
        mainwindow.cpp \
    ../lib/common.cpp \
    ../lib/control.cpp \
    ../lib/decode.cpp \
    ../lib/image.cpp \
    ../lib/realtime.cpp \
    qjumpingsumoimagefeed.cpp

HEADERS  += mainwindow.h \
    qjumpingsumoimagefeed.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
