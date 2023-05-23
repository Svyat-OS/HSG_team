QT += testlib sql network
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_task_test.cpp \
    ../server/func_for_server.cpp \
    ../server/mytcpserver.cpp

HEADERS += \
    ../server/DataBase.h \
    ../server/func_for_server.h \
    ../server/mytcpserver.h
