#include "PixFileSystemModel.h"
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>


PixFileSystemModel::PixFileSystemModel(QObject *parent) :
    QFileSystemModel(parent)
{

}

PixFileSystemModel::~PixFileSystemModel()
{

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
    QFileInfo info = PixFileSystemModel::fileInfo(index);

    if(PixFileSystemModel::PixmapRole == role) {
        if(info.isFile())
        {
            if(QString::compare(info.suffix(), "jpg", Qt::CaseInsensitive) == 0 ||
               QString::compare(info.suffix(), "png", Qt::CaseInsensitive) == 0 ){
                return QPixmap(info.absoluteFilePath());
            }
        }
        else{
            return QPixmap();
        }
    }
    else if(PixFileSystemModel::PixSizeRole == role) {
        if(info.isFile())
        {
            if(QString::compare(info.suffix(), "jpg", Qt::CaseInsensitive) == 0 ||
               QString::compare(info.suffix(), "png", Qt::CaseInsensitive) == 0 ){
                return QPixmap(info.absoluteFilePath()).size();
            }
        }
        else{
            return QSize();
        }
    }
    else if(Qt::TextAlignmentRole == role) {
        return QVariant(Qt::AlignLeft | Qt::AlignVCenter);
    }
//    else if(Qt::FontRole == role) {
//        QFont font;
//        font.setPointSize(12);
//        font.setBold(true);
//        return font;
//    }
    else {
        return QFileSystemModel::data(index, role);
    }
}

