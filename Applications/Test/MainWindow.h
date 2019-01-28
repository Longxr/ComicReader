#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLib7z/include/lib7z_facade.h>
#include <QLib7z/include/init.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    Lib7z::ExtractItemJob* m_pExtractItemJob;
    QFile* m_p7zFile;
};

#endif // MAINWINDOW_H
