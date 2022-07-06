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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTemperature(QDateTime timeStamp, float temp)
{
    ui->tempLabel->setText(QString::number(temp)+"°C");
}

