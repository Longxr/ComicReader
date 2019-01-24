#include "PageSizeSetDlg.h"
#include "ui_PageSizeSetDlg.h"

PageSizeSetDlg::PageSizeSetDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PageSizeSetDlg)
{
    ui->setupUi(this);
}

PageSizeSetDlg::~PageSizeSetDlg()
{
    delete ui;
}

QSize PageSizeSetDlg::GetPageSize()
{
    return QSize(ui->editWidth->text().toInt(), ui->editHeight->text().toInt());
}
