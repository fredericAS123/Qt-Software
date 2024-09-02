
#include "gamewidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gamewidget w;
    w.show();

    return a.exec();

}
