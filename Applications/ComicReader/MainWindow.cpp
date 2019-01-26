
#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QTranslator>
#include <QFileDialog>
#include <QStandardPaths>
#include <QMessageBox>
#include <QPixmap>
#include <QListView>
#include <QTreeView>
#include <QDebug>
#include <QModelIndexList>
#include <QPainter>
#include <QScrollBar>
#include <QActionGroup>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString rootPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    m_pPixModel = new PixFileSystemModel(this);
    m_pPixDelegate = new PixmapDelegate(this);
    m_pPixModel->setReadOnly(true);

    this->initForm();

    SetRootPath(rootPath);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initForm()
{
    this->initTreeView();
    this->initListView();
    this->initStyle();
    this->initTranslator();
}

void MainWindow::initTreeView()
{
    ui->treeView->setModel(m_pPixModel);
    ui->treeView->expandAll();

    connect(ui->treeView, &QTreeView::doubleClicked, this, &MainWindow::showChild);
}

void MainWindow::initListView()
{
    ui->listView->setModel(m_pPixModel);
    ui->listView->setItemDelegate(m_pPixDelegate);
    ui->listView->setSpacing(0);
    ui->listView->setViewMode(QListView::ListMode);
    ui->listView->setResizeMode(QListView::Adjust);
    ui->listView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    ui->listView->verticalScrollBar()->setSingleStep(20);
    ui->listView->setDragEnabled(false);
}

void MainWindow::initStyle()
{
    m_pSkinActionGroup = new QActionGroup(this);
    m_pSkinActionGroup->addAction(ui->actionSkinBlack);
    m_pSkinActionGroup->addAction(ui->actionSkinWhite);
    m_pSkinActionGroup->addAction(ui->actionSkinBlue);

    connect(m_pSkinActionGroup, &QActionGroup::triggered, this, &MainWindow::onSkinActionTriggered);

    onSkinActionTriggered(ui->actionSkinBlue);
}

void MainWindow::initTranslator()
{
    //加载鼠标右键菜单翻译文件
    QTranslator *translator1 = new QTranslator(qApp);
    translator1->load(":/image/qt_zh_CN.qm");
    qApp->installTranslator(translator1);

    //加载富文本框鼠标右键菜单翻译文件
    QTranslator *translator2 = new QTranslator(qApp);
    translator2->load(":/image/widgets.qm");
    qApp->installTranslator(translator2);
}

void MainWindow::showChild(const QModelIndex &index)
{
    QString path = m_pPixModel->fileInfo(index).absoluteFilePath();//获取程序当前文件路径
    qDebug() << "path:" << path;

    if (m_pPixModel->fileInfo(index).isDir())//判断是否为目录
    {
        m_currentDirPath = path;
        ui->listView->setRootIndex(m_pPixModel->index(m_currentDirPath));//进入目录
        ui->treeView->collapseAll();
    }
    else {
        qDebug() << "select is not dir";
    }
}

void MainWindow::onSkinActionTriggered(QAction *pAction)
{
    QFile file;
    if(pAction == ui->actionSkinBlack) {
        file.setFileName(":/qss/psblack.css");
    }
    else if(pAction == ui->actionSkinWhite) {
        file.setFileName(":/qss/flatwhite.css");
    }
    else if(pAction == ui->actionSkinBlue) {
        file.setFileName(":/qss/lightblue.css");
    }

    if (file.open(QFile::ReadOnly)) {
        QString qss = QLatin1String(file.readAll());
        QString paletteColor = qss.mid(20, 7);
        qApp->setPalette(QPalette(QColor(paletteColor)));
        qApp->setStyleSheet(qss);
        file.close();
    }
}

void MainWindow::on_btnRootPath_clicked()
{
    const QString documentLocation = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString strDir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                      documentLocation,
                                                      QFileDialog::ShowDirsOnly
                                                      | QFileDialog::DontResolveSymlinks);

    if(strDir.isEmpty()) {
        QMessageBox::warning(this, tr("警告"), tr("根路径不能为空"));
    }

    QFileInfo infoDir(strDir);
    if(!infoDir.isDir()) {
        QMessageBox::warning(this, tr("警告"), tr("根路径不合法"));
    }

    SetRootPath(strDir);
}

void MainWindow::SetRootPath(const QString &path)
{
    m_currentDirPath = path;
    m_pPixModel->setRootPath(path);

    ui->editRootPath->setText(path);
    ui->treeView->setRootIndex(m_pPixModel->index(m_pPixModel->rootPath()));
    ui->listView->setRootIndex(m_pPixModel->index(m_pPixModel->rootPath()));

    ui->treeView->setFocus();
}

void MainWindow::on_action_C_triggered()
{
    close();
}

void MainWindow::on_spinBoxScrollDistance_valueChanged(int distance)
{
    ui->listView->verticalScrollBar()->setSingleStep(distance);
}
