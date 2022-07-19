#ifndef TEMPERATUREREADING_H
#define TEMPERATUREREADING_H

#include<QDateTime>


class TemperatureReading
{
public:
    TemperatureReading();
    TemperatureReading(const QDateTime &newTimeStamp, float newTemperature);
    float temperatureC() const;
    void setTemperatureC(float newTemperatureC);

    const QDateTime &timeStamp() const;
    void setTimeStamp(const QDateTime &newTimeStamp);
    bool isValid();

private:
    float m_temperatureC;
    QDateTime m_timeStamp;
};

#endif // TEMPERATUREREADING_H
