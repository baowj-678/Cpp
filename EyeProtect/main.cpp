#include "SuspendWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SuspendWindow w;
    w.setApp(&a);
    w.show();
    return a.exec();
}
