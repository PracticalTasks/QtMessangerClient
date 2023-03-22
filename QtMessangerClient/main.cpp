#include "QtMessangerClient.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtMessangerClient w;
    w.show();
    return a.exec();
}
