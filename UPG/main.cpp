#include <QtCore/QCoreApplication>
#include <QTime>
#include "App.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    App app;

    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    return a.exec();
}
