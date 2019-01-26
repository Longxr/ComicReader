#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "PixFileSystemModel.h"
#include "PixmapDelegate.h"

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
    void initForm();
    void initTreeView();
    void initListView();
    void initStyle();
    void initTranslator();
    void showChild(const QModelIndex &index);
    void setAddressPath(const QModelIndex &index);

    void on_btnRootPath_clicked();
    void on_action_C_triggered();
    void on_spinBoxScrollDistance_valueChanged(int distance);

private:
    void SetRootPath(const QString& path);

private:
    Ui::MainWindow *ui;

    QString             m_currentDirPath;
    PixFileSystemModel* m_pPixModel;
    PixmapDelegate*     m_pPixDelegate;
};

#endif // MAINWINDOW_H
