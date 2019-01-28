/**************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the Qt Installer Framework.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
**
** $QT_END_LICENSE$
**
**************************************************************************/

#include "fileio.h"

#include "errors.h"
#include "range.h"

#include <QCoreApplication>
#include <QByteArray>
#include <QFileDevice>
#include <QString>

qint64 QInstaller::retrieveInt64(QFileDevice *in)
{
    qint64 n = 0;
    QInstaller::blockingRead(in, reinterpret_cast<char*>(&n), sizeof(n));
    return n;
}

void QInstaller::appendInt64(QFileDevice *out, qint64 n)
{
    QInstaller::blockingWrite(out, reinterpret_cast<const char*>(&n), sizeof(n));
}

Range<qint64> QInstaller::retrieveInt64Range(QFileDevice *in)
{
    const quint64 start = QInstaller::retrieveInt64(in);
    const quint64 length = QInstaller::retrieveInt64(in);
    return Range<qint64>::fromStartAndLength(start, length);
}

void QInstaller::appendInt64Range(QFileDevice *out, const Range<qint64> &r)
{
    QInstaller::appendInt64(out, r.start());
    QInstaller::appendInt64(out, r.length());
}

QString QInstaller::retrieveString(QFileDevice *in)
{
    return QString::fromUtf8(QInstaller::retrieveByteArray(in));
}

void QInstaller::appendString(QFileDevice *out, const QString &str)
{
    QInstaller::appendByteArray(out, str.toUtf8());
}

QByteArray QInstaller::retrieveByteArray(QFileDevice *in)
{
    QByteArray ba(QInstaller::retrieveInt64(in), '\0');
    QInstaller::blockingRead(in, ba.data(), ba.size());
    return ba;
}

void QInstaller::appendByteArray(QFileDevice *out, const QByteArray &ba)
{
    QInstaller::appendInt64(out, ba.size());
    QInstaller::blockingWrite(out, ba.constData(), ba.size());
}

QByteArray QInstaller::retrieveData(QFileDevice *in, qint64 size)
{
    QByteArray ba(size, '\0');
    QInstaller::blockingRead(in, ba.data(), size);
    return ba;
}

void QInstaller::appendData(QFileDevice *out, QFileDevice *in, qint64 size)
{
    Q_ASSERT(!in->isSequential());
    QInstaller::blockingCopy(in, out, size);
}

void QInstaller::openForRead(QFileDevice *dev)
{
    Q_ASSERT(dev);
    if (!dev->open(QIODevice::ReadOnly)) {
        throw Error(QCoreApplication::translate("QInstaller",
            "Cannot open file %1 for reading: %2").arg(dev->fileName(), dev->errorString()));
    }
}

void QInstaller::openForWrite(QFileDevice *dev)
{
    Q_ASSERT(dev);
    if (!dev->open(QIODevice::WriteOnly)) {
        throw Error(QCoreApplication::translate("QInstaller",
            "Cannot open file %1 for writing: %2").arg(dev->fileName(), dev->errorString()));
    }
}

void QInstaller::openForAppend(QFileDevice *dev)
{
    Q_ASSERT(dev);
    if (!dev->open(QIODevice::WriteOnly | QIODevice::Append)) {
        throw Error(QCoreApplication::translate("QInstaller",
            "Cannot open file %1 for writing: %2").arg(dev->fileName(), dev->errorString()));
    }
}

qint64 QInstaller::blockingRead(QFileDevice *in, char *buffer, qint64 size)
{
    if (in->atEnd())
        return 0;
    qint64 left = size;
    while (left > 0) {
        const qint64 n = in->read(buffer, left);
        if (n < 0) {
            throw Error(QCoreApplication::translate("QInstaller",
                "Read failed after %1 bytes: %2").arg(QString::number(size - left),
                in->errorString()));
        }
        left -= n;
        buffer += n;
    }
    return size;
}

qint64 QInstaller::blockingCopy(QFileDevice *in, QFileDevice *out, qint64 size)
{
    static const qint64 blockSize = 4096;
    QByteArray ba(blockSize, '\0');
    qint64 actual = qMin(blockSize, size);
    while (actual > 0) {
        try {
            QInstaller::blockingRead(in, ba.data(), actual);
            QInstaller::blockingWrite(out, ba.constData(), actual);
            size -= actual;
            actual = qMin(blockSize, size);
        } catch (const Error &error) {
            throw Error(QCoreApplication::translate("QInstaller", "Copy failed. Error: %1")
                .arg(error.message()));
        }
    }
    return size;
}

qint64 QInstaller::blockingWrite(QFileDevice *out, const QByteArray &data)
{
    return QInstaller::blockingWrite(out, data.constData(), data.size());
}

qint64 QInstaller::blockingWrite(QFileDevice *out, const char *data, qint64 size)
{
    qint64 left = size;
    while (left > 0) {
        const qint64 n = out->write(data, left);
        if (n < 0) {
            throw Error(QCoreApplication::translate("QInstaller",
                "Write failed after %1 bytes: %2").arg(QString::number(size - left),
                out->errorString()));
        }
        left -= n;
    }
    return size;
}
