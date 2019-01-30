#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QActionGroup>

#include "ComicDirModel.h"
#include "PixFileSystemModel.h"
#include "PixmapDelegate.h"
#include "ExtractArchiveManager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onShowComic(const QModelIndex &index);
    void onSkinActionTriggered(QAction* pAction);

    void on_btnRootPath_clicked();
    void on_action_C_triggered();
    void on_spinBoxScrollDistance_valueChanged(int distance);

private:
    void initForm();
    void initTreeView();
    void initListView();
    void initStyle();
    void initTranslator();

    void SetRootPath(const QString& path);

private:
    Ui::MainWindow *ui;

    QString             m_currentDirPath;
    ComicDirModel*      m_pDirModel;
    PixFileSystemModel* m_pPixModel;
    PixmapDelegate*     m_pPixDelegate;
    QActionGroup*       m_pSkinActionGroup;

    ExtractArchiveManager* m_pExtractArchiveManager;
};

#endif // MAINWINDOW_H
