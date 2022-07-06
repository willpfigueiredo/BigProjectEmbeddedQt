#ifndef MOCKTEMPSENSOR_H
#define MOCKTEMPSENSOR_H

#include <QObject>
#include "TemperatureSensorIF.h"
#include <QTimer>

class MockTempSensor : public TemperatureSensorIF
{
    Q_OBJECT
public:
    explicit MockTempSensor(QObject *parent = nullptr);

signals:

private:
    float m_lastTemp;
    QTimer m_sendTimer;

};

#endif // MOCKTEMPSENSOR_H
