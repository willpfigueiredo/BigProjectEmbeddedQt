#include "MockTempSensor.h"
#include <QDateTime>

MockTempSensor::MockTempSensor(QObject *parent)
    : TemperatureSensorIF{parent}
    , m_lastTemp{20.0}
{
    m_sendTimer.setInterval(2000);
    connect(&m_sendTimer, &QTimer::timeout, [&](){
       QDateTime now = QDateTime::currentDateTime();
       float change = static_cast<float>(now.time().second() % 10 - 5);
       m_lastTemp += change;
       emit newTemperature(now, m_lastTemp);
    });

    m_sendTimer.start();


}
