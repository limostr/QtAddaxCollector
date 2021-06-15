#ifndef ROLTECHSYNCHRO_H
#define ROLTECHSYNCHRO_H

#include <QObject>
#include <QDebug>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>


const static QUrl C__server(QLatin1String("http://addax.roltech.systems/public/webservice/day/get"));
const static QString C__InitDayService(QLatin1String("get"));
const static QString contentTypeJson(QLatin1String("application/json"));
const static QString C__UserNameWS__="roltech";
const static QString C__PassWordWS__="roltech";



class RoltechSynchro : public QObject
{
    Q_OBJECT

public:
    RoltechSynchro();
    void InitDay();

public slots:
    void InitDayReader(QNetworkReply *m_reply);
private :

QNetworkAccessManager *naManager;


};

#endif // ROLTECHSYNCHRO_H
