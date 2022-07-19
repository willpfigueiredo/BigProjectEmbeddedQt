#ifndef TEMPERATURESTORAGE_H
#define TEMPERATURESTORAGE_H

#include <QSqlDatabase>
#include"TemperatureReading.h"

class TemperatureStorage
{
public:
    TemperatureStorage();

    void addReading(const TemperatureReading &reading);
    QList<TemperatureReading> getAllReadings() const;
    QList<TemperatureReading> getLastNReadings(int n) const;
    TemperatureReading getLastReading() const;

    void clearAllReadings();
    int numberOfreadings();

    bool openStorage(const QString &id= "readings");
    bool closeStorage();
    QString id() const;
private:
    QSqlDatabase m_db;
    QString m_id;
};

#endif // TEMPERATURESTORAGE_H
