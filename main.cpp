#include "mainwindow.h"

#include <QApplication>
#include "MockTempSensor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MockTempSensor tempSensor;
    MainWindow w(&tempSensor);
    w.show();
    return a.exec();
}
