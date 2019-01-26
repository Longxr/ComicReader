#include "PixmapDelegate.h"
#include <QPainter>
#include "PixFileSystemModel.h"

PixmapDelegate::PixmapDelegate(QObject *parent) : QStyledItemDelegate(parent)
{

}

PixmapDelegate::~PixmapDelegate()
{

}

void PixmapDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.isValid())
    {
        painter->save();

        QPixmap pix = index.data(PixFileSystemModel::PixmapRole).value<QPixmap>();
        QRect rect = option.rect.adjusted(1, 1, -1, -1);
        QSize newSize = pix.size().scaled(rect.size(), Qt::KeepAspectRatio);
        int xOffset = (rect.width() - newSize.width()) / 2;
        int yOffset = (rect.height() - newSize.height()) / 2;
        QRect newRect = rect.adjusted(xOffset, yOffset, -xOffset, -yOffset);

        if(!pix.isNull()) {
            painter->drawPixmap(newRect, pix);
        }

        painter->restore();
    }
}

QSize PixmapDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &/*index*/) const
{
//    QSize size = m_pageSize.scaled(QSize(option.rect.width(), option.rect.width() * 2), Qt::KeepAspectRatio);
    return QSize(option.rect.width(), option.rect.width() * 3 / 2);
}
