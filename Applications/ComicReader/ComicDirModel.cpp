#include "ComicDirModel.h"

ComicDirModel::ComicDirModel(QObject *parent) : QFileSystemModel(parent)
{
    setReadOnly(true);

    setNameFilterDisables(false);
    QStringList filter;
    filter << "*.zip" << "*.rar" << "*.7z";
    setNameFilters(filter);
}

int ComicDirModel::rowCount(const QModelIndex &parent) const
{
    if(rootPath().isEmpty())
        return 0;
    return QFileSystemModel::rowCount(parent);
}

int ComicDirModel::columnCount(const QModelIndex &) const
{
    return 1;
}

QVariant ComicDirModel::data(const QModelIndex &index, int role) const
{
    if(Qt::TextAlignmentRole == role) {
        return QVariant(Qt::AlignLeft | Qt::AlignVCenter);
    }
//    else if(Qt::FontRole == role) {
//        QFont font;
//        font.setPointSize(12);
//        font.setBold(true);
//        return font;
//    }

    return QFileSystemModel::data(index, role);
}
