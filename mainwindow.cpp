#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSerialPort/QSerialPortInfo>
#include <QTextStream>
#include <QList>
#include <QDebug>
#include <QMessageBox>
#include <QtSql/QSql>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

 ui->setupUi(this);
   //connect(serial1, SIGNAL(readyRead()), this, SLOT(readDataFromDiscovery()));

   ui->m_waitRequestSpinBox->setRange(0, 10000);
   ui->m_waitRequestSpinBox->setValue(20);

   QList<QSerialPortInfo> infoList = QSerialPortInfo::availablePorts();
   foreach(QSerialPortInfo info, infoList) {
      ui->m_serialPortComboBox->addItem(info.portName());
       //qDebug() << "Port:" << info.portName();
   }


   decoder = new RoltechRFIDDecoder();
}


void MainWindow::initComPort(void)
{
    this->serial1 = new QSerialPort(this);
    connect(serial1, SIGNAL(readyRead()), this, SLOT(readData()));
    serial1->setPortName(ui->m_serialPortComboBox->currentText());

    if (serial1->open(QSerialPort::ReadWrite))
    {
        qDebug("SERIAL PORT - OPENED") ;
        serial1->setBaudRate(QSerialPort::Baud9600);
        serial1->setDataBits(QSerialPort::Data8);
        serial1->setParity(QSerialPort::NoParity);
        serial1->setStopBits(QSerialPort::OneStop);
        serial1->setFlowControl(QSerialPort::NoFlowControl);


    }
    else
    {
        qDebug("SERIAL PORT - NOT OPENED") ;

    }

}
void MainWindow::readData(){
    QByteArray data = serial1->readAll();
char null_char = '\0';
QString dataCorrect=data.replace(null_char,'0');
     qDebug() <<"data:" << dataCorrect;
    decoder->AppendRecevedTram(dataCorrect);
     this->ui->m_ReponseReded->append(dataCorrect);
}
void MainWindow::closeSerialPort()
{
    if (serial1->isOpen()){
        serial1->close();

    }
QMessageBox::information(this, "Close Port","Closed serial port");

}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_m_btn_ReloadPorts_clicked()
{
    QList<QSerialPortInfo> infoList = QSerialPortInfo::availablePorts();
    foreach(QSerialPortInfo info, infoList) {
       ui->m_serialPortComboBox->addItem(info.portName());
    }


}


void MainWindow::on_m_StartBtn_clicked()
{
    this->initComPort();

}


void MainWindow::on_pushButton_clicked()
{
    this->closeSerialPort();
}

