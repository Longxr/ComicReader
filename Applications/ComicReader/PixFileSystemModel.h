#ifndef PIXFILESYSTEMMODEL_H
#define PIXFILESYSTEMMODEL_H

#include <QFileSystemModel>

class PixFileSystemModel : public QFileSystemModel
{
    Q_OBJECT

public:
    enum {
        PixmapRole = Qt::UserRole + 4,
        PixSizeRole = Qt::UserRole + 5,
    };

    explicit PixFileSystemModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;

protected:
    virtual int columnCount(const QModelIndex &) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
};

#endif // PIXFILESYSTEMMODEL_H
