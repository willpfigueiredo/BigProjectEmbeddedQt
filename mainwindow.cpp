#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(TemperatureSensorIF *tempSensor, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&m_timer, &QTimer::timeout, [&](){
        QDateTime now = QDateTime::currentDateTime();
        ui->timeDateLabel->setText(now.toString());
    });

    m_timer.start(1000);

    connect(tempSensor, &TemperatureSensorIF::newTemperature, this, &MainWindow::updateTemperature);
    connect(tempSensor, &TemperatureSensorIF::newTemperature, ui->historyForm, &::TemperatureHistoryForm::tempeatureUpdate);

    m_hvacSM.connectToState("Heating", ui->heatingInd, &QLabel::setEnabled);
    m_hvacSM.connectToState("Cooling", ui->coolingInd, &QLabel::setEnabled);
    m_hvacSM.connectToState("FanOn", ui->fanInd, &QLabel::setEnabled);

    m_hvacSM.connectToState("Heating", &m_hvacCtrl, &HVACController::setHeatingOn);
    m_hvacSM.connectToState("Cooling", &m_hvacCtrl, &HVACController::setCoolingOn);
    m_hvacSM.connectToState("FanOn", &m_hvacCtrl, &HVACController::setFanOn);

    m_hvacSM.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTemperature(QDateTime timeStamp, float temp)
{
    ui->tempLabel->setText(QString::number(temp)+"°C");
}

