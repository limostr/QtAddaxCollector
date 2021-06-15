#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QTimer>
#include "RoltechLib/roltechrfiddecoder.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initComPort();
private slots:
    void on_m_btn_ReloadPorts_clicked();

    void on_m_StartBtn_clicked();
    void closeSerialPort();
    void on_pushButton_clicked();
    void readData();
private:
    Ui::MainWindow *ui;
    QSerialPort *serial1;

    QByteArray m_request;
    QTimer m_timer;


     RoltechRFIDDecoder *decoder;
};
#endif // MAINWINDOW_H
