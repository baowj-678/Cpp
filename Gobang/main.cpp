#include "Gobang.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Gobang w;
	w.show();
	return a.exec();
}
