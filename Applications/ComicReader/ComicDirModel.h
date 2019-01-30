#ifndef COMICDIRMODEL_H
#define COMICDIRMODEL_H

#include <QFileSystemModel>

class ComicDirModel : public QFileSystemModel
{
    Q_OBJECT
public:
    explicit ComicDirModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;

protected:
    virtual int columnCount(const QModelIndex &) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
};

#endif // COMICDIRMODEL_H
