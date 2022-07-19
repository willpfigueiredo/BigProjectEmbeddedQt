#include "TemperatureStorage.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlTableModel>
#include <QSqlRecord>

TemperatureStorage::TemperatureStorage()
{

}

void TemperatureStorage::addReading(const TemperatureReading &reading)
{
    QSqlQuery query(m_db);
    query.prepare("insert into TemeratureHistory values (:timeStamp, :temperature);");
    query.bindValue(":timeStamp", reading.timeStamp());
    query.bindValue(":temperature", reading.temperatureC());
    query.exec();
}

QList<TemperatureReading> TemperatureStorage::getAllReadings() const
{
    QSqlTableModel model(nullptr, m_db);
    model.setTable("TemperatureHistory");
    model.select();

    QList<TemperatureReading> data;

    for(int row = 0; row < model.rowCount(); row++)
    {
        auto rec = model.record(row);
        data << TemperatureReading(rec.value("timeStamp").toDateTime(),
                                   rec.value("temperature").toFloat());
    }

    return data;
}

QList<TemperatureReading> TemperatureStorage::getLastNReadings(int n) const
{
    QString qStr = QString("select * from TemperatureHistory order by timeStamp desc limit %1").arg(n);

    QSqlQuery query(qStr, m_db);
    query.exec();

    QList<TemperatureReading> readings;

    while(query.next())
    {
        readings.append(TemperatureReading(query.value("timeStamp").toDateTime(),
                                           query.value("temperature").toFloat() ));
    }

    return readings;
}

bool TemperatureStorage::openStorage(const QString &id)
{
    QString dbName = QString("ReadingStore_%1").arg(id);
    QString dbFileName = QString("%1.sqlite").arg(dbName);

    m_db = QSqlDatabase::addDatabase("QSQLITE", dbName);
    m_db.setDatabaseName(dbFileName);
    bool result = m_db.open();

    if(result)
    {
        QSqlQuery query(m_db);
        result = query.exec("create table if not exists"
                            "TemperatureHistory("
                           "timeStamp dateTime primaryKey,"
                           "temperature float);");

    }

    return result;
}

bool TemperatureStorage::closeStorage()
{
    m_db.close();
}
