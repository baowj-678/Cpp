#include "PhilosophyEating.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PhilosophyEating w;
	w.show();
	return a.exec();
}
