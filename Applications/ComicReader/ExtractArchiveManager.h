#ifndef EXTRACTARCHIVEMANAGER_H
#define EXTRACTARCHIVEMANAGER_H

#include <QObject>
#include <QLib7z/include/lib7z_facade.h>
#include <QLib7z/include/init.h>
#include <quazip/JlCompress.h>

class ExtractArchiveManager : public QObject
{
    Q_OBJECT
public:
    enum FILE_TYPE {
        FILE_TYPE_NOT_SUPPORT = 0,
        FILE_TYPE_7Z,
        FILE_TYPE_ZIP,
        FILE_TYPE_RAR,
    };

    explicit ExtractArchiveManager(QObject *parent = 0);
    ~ExtractArchiveManager();

    void startExtractArchive(const QString& path);

signals:

private slots:
    void onDealProgress(qint64 completed, qint64 total);
    void onFinished();

private:
    void extractArchive7z();
    void extractArchiveZip();
    void extractArchiveRar();

private:
    QString     m_srcPath;
    QString     m_desPath;
    QString     m_tempPath;
    FILE_TYPE   m_type;

    QFile*      m_pFile;
    Lib7z::ExtractItemJob* m_p7ZExtract;
};

#endif // EXTRACTARCHIVEMANAGER_H
