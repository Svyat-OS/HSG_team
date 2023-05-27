QT += testlib
QT -= gui
QT+= core
QT += sql
QT += network

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_test4.cpp \
    ../../Main_Server/server/func_for_server.cpp \
    ../../Main_Server/server/mytcpserver.cpp

DISTFILES += \
    ../../Main_Server/server/my_data_base.db

HEADERS += \
    ../../Main_Server/server/DataBase.h \
    ../../Main_Server/server/func_for_server.h \
    ../../Main_Server/server/mytcpserver.h
