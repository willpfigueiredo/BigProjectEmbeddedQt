#include "mainwindow.h"

#include <QApplication>
#include "MockTempSensor.h"

int main(int argc, char *argv[])
{
    // virtual keyboard
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));
    qputenv("QT_LOGGING_RULES", QByteArray("qt.virtualkeyboard=true"));
    QApplication a(argc, argv);
    MockTempSensor tempSensor;
    MainWindow w(&tempSensor);
    w.show();
    return a.exec();
}
