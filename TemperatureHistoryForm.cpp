#include "TemperatureHistoryForm.h"
#include "ui_TemperatureHistoryForm.h"
#include <QQmlEngine>
#include <QQmlContext>

TemperatureHistoryForm::TemperatureHistoryForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TemperatureHistoryForm)
{
    ui->setupUi(this);
    m_tempProxy .setSourceModel(&m_tempRecord);
    ui->tableView->setModel(&m_tempProxy);

    /** setup the QtQuick Chart **/
    ui->quickWidget->resize(QSize(640, 480));
    ui->quickWidget->engine()->rootContext()->setContextProperty("temperatureData", this);
    ui->quickWidget->setSource(QUrl("qrc:/TemperatureChart.qml"));
    ui->quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
}

TemperatureHistoryForm::~TemperatureHistoryForm()
{
    delete ui;
}

QPointF TemperatureHistoryForm::lastReading()
{
    return m_lastReading;
}

void TemperatureHistoryForm::setLastReading(const QPointF &value)
{
    m_lastReading = value;
    emit newReading();
}

void TemperatureHistoryForm::tempeatureUpdate(QDateTime timeStamp, float temperature)
{
    auto time = new QStandardItem;
    auto temp = new QStandardItem;

    time->setData(timeStamp, Qt::DisplayRole);
    temp->setData(temperature, Qt::DisplayRole);

    QList<QStandardItem *> row;
    row << time << temp;

    m_tempRecord.appendRow(row);

    double xVal = timeStamp.toSecsSinceEpoch();
    setLastReading(QPointF(xVal, temperature));
}
