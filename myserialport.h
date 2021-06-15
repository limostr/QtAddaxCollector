#ifndef MYSERIALPORT_H
#define MYSERIALPORT_H
#include <QtSerialPort/QtSerialPort>
#include <QObject>

class MySerialPort: public QSerialPort
{
     Q_OBJECT
public:
    MySerialPort();

public slots:
    void openSerialPort();
    void closeSerialPort();

    void writeData(const QByteArray &data);
    void readData();

    void handleError(QSerialPort::SerialPortError error);

private:
    void showStatusMessage(const QString &message);

    QSerialPort *serial;

};
#endif // MYSERIALPORT_H
