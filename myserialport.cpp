#include "myserialport.h"
#include <QtSerialPort/QSerialPort>
#include <QMessageBox>
#include <QObject>

MySerialPort::MySerialPort()
{
    serial = new QSerialPort(this);
    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
    //openSerialPort();
}


void MySerialPort::openSerialPort()
{
    serial->setPortName("COM3");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    if (serial->open(QIODevice::ReadWrite)) {

        showStatusMessage("Connectedd");

    } else {

        showStatusMessage(tr("Open error"));
    }
}

void MySerialPort::closeSerialPort()
{
    if (serial->isOpen())
        serial->close();

    showStatusMessage(tr("Disconnected"));
}

void MySerialPort::writeData(const QByteArray &data)
{
    serial->write(data);
}

void MySerialPort::readData()
{
   QByteArray data = serial->readAll();

   qDebug() << data;

}

void MySerialPort::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        closeSerialPort();
    }
}


void MySerialPort::showStatusMessage(const QString &message)
{
    qDebug() << message;
}
