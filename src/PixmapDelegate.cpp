#include "PixmapDelegate.h"
#include <QPainter>>
#include "PixFileSystemModel.h"

PixmapDelegate::PixmapDelegate(QObject *parent) : QStyledItemDelegate(parent)
{
    m_pageSize = QSize(550, 800);
}

PixmapDelegate::~PixmapDelegate()
{

}

void PixmapDelegate::SetPageSize(const QSize &size)
{
    m_pageSize = size;
}

void PixmapDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.isValid())
    {
        painter->save();

        QPixmap pix = index.data(PixFileSystemModel::PixmapRole).value<QPixmap>();
        QRect rect = option.rect.adjusted(1, 1, -1, -1);
        painter->drawPixmap(rect, pix);

        painter->restore();
    }
}

QSize PixmapDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSize size = m_pageSize.scaled(QSize(option.rect.width(), option.rect.width() * 2), Qt::KeepAspectRatio);
    return size;
}
