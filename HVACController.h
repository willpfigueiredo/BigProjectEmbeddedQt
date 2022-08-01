#ifndef HVACCONTROLLER_H
#define HVACCONTROLLER_H

#include <QObject>

class HVACController : public QObject
{
    Q_OBJECT
public:
    explicit HVACController(QObject *parent = nullptr);

public slots:
    void setHeatingOn();
    void setCoolingOn();
    void setFanOn();

signals:

};

#endif // HVACCONTROLLER_H
