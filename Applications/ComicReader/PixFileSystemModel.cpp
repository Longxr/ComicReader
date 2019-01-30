#include "PixFileSystemModel.h"
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>


PixFileSystemModel::PixFileSystemModel(QObject *parent) :
    QFileSystemModel(parent)
{
    setReadOnly(true);

//    setFilter(QDir::Files);
    setNameFilterDisables(false);
    QStringList filter;
    filter << "*.png" << "*.jpg" << "*.bmp";
    setNameFilters(filter);
}

int PixFileSystemModel::rowCount(const QModelIndex &parent) const
{
    if(rootPath().isEmpty())
        return 0;
    return QFileSystemModel::rowCount(parent);
}

int PixFileSystemModel::columnCount(const QModelIndex &) const
{
    return 1;
}

QVariant PixFileSystemModel::data( const QModelIndex& index, int role ) const
{
    if(PixFileSystemModel::PixmapRole == role) {
        QFileInfo info = PixFileSystemModel::fileInfo(index);
        if(info.isFile())
        {
            if(QString::compare(info.suffix(), "jpg", Qt::CaseInsensitive) == 0 ||
               QString::compare(info.suffix(), "png", Qt::CaseInsensitive) == 0 ||
               QString::compare(info.suffix(), "bmp", Qt::CaseInsensitive) == 0 ){
                return QPixmap(info.absoluteFilePath());
            }
        }
    }

    return QFileSystemModel::data(index, role);
}

