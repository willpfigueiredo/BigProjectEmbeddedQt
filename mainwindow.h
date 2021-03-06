#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDateTime>
#include "TemperatureSensorIF.h"
#include "TemperatureHistoryForm.h"
#include "HVACControl.h"
#include "HVACController.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(TemperatureSensorIF* tempSensor, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateTemperature(QDateTime timeStamp, float temp);

private:
    Ui::MainWindow *ui;
    QTimer m_timer;
    TemperatureSensorIF* m_tempSensor;
    HVACControl m_hvacSM;
    HVACController m_hvacCtrl;


};
#endif // MAINWINDOW_H
