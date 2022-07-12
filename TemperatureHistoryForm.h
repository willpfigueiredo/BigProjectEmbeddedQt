#ifndef TEMPERATUREHISTORYFORM_H
#define TEMPERATUREHISTORYFORM_H

#include <QWidget>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include <QDateTime>

namespace Ui {
class TemperatureHistoryForm;
}

class TemperatureHistoryForm : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QPointF lastReading READ lastReading WRITE setLastReading NOTIFY newReading);

public:
    explicit TemperatureHistoryForm(QWidget *parent = nullptr);
    ~TemperatureHistoryForm();
    QPointF lastReading();
    void setLastReading(const QPointF& value);

public slots:
    void tempeatureUpdate(QDateTime timeStamp, float temperature);

signals:
    void newReading();


private:
    Ui::TemperatureHistoryForm *ui;
    QStandardItemModel m_tempRecord; ///a record of time and temperature
    QSortFilterProxyModel m_tempProxy; ///a way to sort/filter m_tempRecord
    QPointF m_lastReading;
};

#endif // TEMPERATUREHISTORYFORM_H
