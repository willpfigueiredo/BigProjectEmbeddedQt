#include "TemperatureReading.h"

TemperatureReading::TemperatureReading()
    :m_temperatureC(0.0)
    ,m_timeStamp(QDateTime())
{

}

TemperatureReading::TemperatureReading(const QDateTime &newTimeStamp, float newTemperature)
{
    m_timeStamp = newTimeStamp;
    m_temperatureC = newTemperature;
}

float TemperatureReading::temperatureC() const
{
    return m_temperatureC;
}

void TemperatureReading::setTemperatureC(float newTemperatureC)
{
    m_temperatureC = newTemperatureC;
}

const QDateTime &TemperatureReading::timeStamp() const
{
    return m_timeStamp;
}

void TemperatureReading::setTimeStamp(const QDateTime &newTimeStamp)
{
    m_timeStamp = newTimeStamp;
}

bool TemperatureReading::isValid()
{
    return m_timeStamp.isValid();
}
