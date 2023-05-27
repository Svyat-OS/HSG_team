#ifndef FUNC_FOR_SERVER_H
#define FUNC_FOR_SERVER_H
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QTcpSocket>
#include <QList>
#include <QMap>

QString parsing(QString str, int descriptor);
QString task1(QStringList params,int descriptor);
QString task2(QStringList params, int descriptor);
QString task3(QStringList params,int descriptor);
QString task4(QStringList params,int descriptor);
QString author(QStringList params,int descriptor);
QString reg(QStringList params,int descriptor);
QString stat(QStringList params,int descriptor);

#endif // FUNC_FOR_SERVER_H
