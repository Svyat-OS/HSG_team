QT += testlib
QT -= gui
QT+= core
QT += sql
QT += network
CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_test2.cpp \
    ../server/func_for_server.cpp \
    ../server/mytcpserver.cpp

DISTFILES += \
    ../server/my_data_base.db

HEADERS += \
    ../server/DataBase.h \
    ../server/func_for_server.h \
    ../server/mytcpserver.h
