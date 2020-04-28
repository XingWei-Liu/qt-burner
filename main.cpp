#include "widget.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QString>

extern "C"{
#include "kylin_api.h"
}

int main(int argc, char *argv[])
{
    kylin_init_gtk(argc, argv);

    QApplication a(argc, argv);

    QApplication::addLibraryPath("./pic");
    a.setWindowIcon(QIcon(":/new/prefix1/pic/logo.ico"));
    QDesktopWidget *desktop = a.desktop();
    Widget w;
    w.move(desktop->width() / 2 - w.width() / 2, desktop->height() / 2 - w.height() / 2);
    w.resize(900, 600);
    w.show();

    return a.exec();
}
