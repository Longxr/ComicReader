#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Lib7z::init();

    QString filePath = QCoreApplication::applicationDirPath() + "/BiuBiuBiu.7z";
    qDebug() << filePath;

    qDebug() << Lib7z::isSupportedArchive(QCoreApplication::applicationDirPath() + "/invaild.7z");
    qDebug() << Lib7z::isSupportedArchive(filePath);

    QFile file(filePath);
    file.open(QFile::ReadOnly);
    Lib7z::extractArchive(&file,QDir::currentPath());
}
