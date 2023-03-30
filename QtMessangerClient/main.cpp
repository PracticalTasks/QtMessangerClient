#include "QtMessangerClient.h"
#include <QtWidgets/QApplication>
#include "AuthentWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AuthentWindow authentWindow;
    authentWindow.show();
    //QtMessangerClient w;
    //w.show();
    return a.exec();
}
