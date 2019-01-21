#ifndef PAGESIZESETDLG_H
#define PAGESIZESETDLG_H

#include <QDialog>

namespace Ui {
class PageSizeSetDlg;
}

class PageSizeSetDlg : public QDialog
{
    Q_OBJECT

public:
    explicit PageSizeSetDlg(QWidget *parent = 0);
    ~PageSizeSetDlg();

    QSize GetPageSize();

private:
    Ui::PageSizeSetDlg *ui;
};

#endif // PAGESIZESETDLG_H
