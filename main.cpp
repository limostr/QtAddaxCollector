#include "mainwindow.h"

#include <QApplication>
#include <QQmlApplicationEngine>
#include "RoltechLib/roltechsynchro.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/InitDayMonitoring.qml")));


    RoltechSynchro *synchro = new RoltechSynchro();
    synchro->InitDay();

   /* MainWindow w;
    w.show();*/
    return a.exec();
}
