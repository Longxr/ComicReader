#ifndef PIXMAPDELEGATE_H
#define PIXMAPDELEGATE_H

#include <QStyledItemDelegate>

class PixmapDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    PixmapDelegate(QObject *parent = 0);
    ~PixmapDelegate();

    void SetPageSize(const QSize& size);

    void paint(QPainter * painter,const QStyleOptionViewItem & option,const QModelIndex & index) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
    QSize m_pageSize;
};

#endif // PIXMAPDELEGATE_H
