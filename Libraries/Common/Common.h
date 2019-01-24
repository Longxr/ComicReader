#ifndef COMMON_H
#define COMMON_H

#include <Common/common_global.h>
#include <Common/AppManager/AppManager.h>

#include <QDateTime>
#include <QThread>
#include <QDebug>

#define BASE_LOG \
    qDebug() << QDateTime::currentDateTime().toString("hh:mm:ss.zzz").toUtf8().data() \
    << " [" << QThread::currentThreadId() << "]" <<  __FILE__ << ":" << __LINE__ << "> "

#endif // COMMON_H
