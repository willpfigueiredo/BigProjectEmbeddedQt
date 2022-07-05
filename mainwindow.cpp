#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&m_timer, &QTimer::timeout, [&](){
        QDateTime now = QDateTime::currentDateTime();
        ui->timeDateLabel->setText(now.toString());
    });

    m_timer.start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

