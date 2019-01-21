#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setFont(QApplication::font("QMenu"));
    a.setWindowIcon(QIcon(":/main.ico"));

    MainWindow w;
    w.setWindowTitle("本地漫画浏览-学妹特供版");
    w.show();

    return a.exec();
}
