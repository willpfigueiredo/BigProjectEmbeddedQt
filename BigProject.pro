QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets quick quickwidgets sql scxml

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MockTempSensor.cpp \
    TemperatureHistoryForm.cpp \
    TemperatureReading.cpp \
    TemperatureSensorIF.cpp \
    TemperatureStorage.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    MockTempSensor.h \
    TemperatureHistoryForm.h \
    TemperatureReading.h \
    TemperatureSensorIF.h \
    TemperatureStorage.h \
    mainwindow.h

FORMS += \
    TemperatureHistoryForm.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qml.qrc

STATECHARTS += \
    HVACControl.scxml
