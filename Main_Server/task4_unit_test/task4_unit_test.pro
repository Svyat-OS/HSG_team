QT += testlib
QT -= gui
QT+= core
QT += sql #для работы с БД
QT += network #Для работы с сетью

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
CONFIG += c++17 console

TEMPLATE = app

SOURCES +=  tst_task4_unit_test.cpp \
    ../server/func_for_server.cpp \
    ../server/mytcpserver.cpp

DISTFILES += \
    ../server/my_data_base.db

HEADERS += \
    ../server/DataBase.h \
    ../server/func_for_server.h \
    ../server/mytcpserver.h

DEFINES += QT_DEPRECATED_WARNINGS

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
