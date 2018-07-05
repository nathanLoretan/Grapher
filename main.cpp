#include "factory.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Factory factory;
    return a.exec();
}
