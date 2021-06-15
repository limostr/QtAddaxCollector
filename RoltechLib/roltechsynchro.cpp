#include "roltechsynchro.h"
#include <QDir>
#include "qtjson/json.h"
RoltechSynchro::RoltechSynchro()
{

}

void RoltechSynchro::InitDay()
{


      QNetworkRequest request;
       naManager = new QNetworkAccessManager(this);
      connect(naManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(InitDayReader(QNetworkReply*)));


      request.setUrl(QUrl("http://addax.roltech.systems/public/webservice/day/get"));
      naManager->get(request);
}



void RoltechSynchro::InitDayReader(QNetworkReply *m_reply)
{

    if (m_reply->error() != QNetworkReply::NoError)
        {
            qDebug() << "Network error: " << m_reply->error();
        }
        else
        {
           // qDebug() << m_reply->readAll();
        }
    QString strReply = (QString)m_reply->readAll();


    //qDebug() << strReply.toUtf8();





           bool ok;
           // json is a QString containing the JSON data
           QtJson::JsonObject result = QtJson::parse(strReply.toUtf8(), ok).toMap();

           if(!ok) {
             qFatal("An error occurred during parsing");
           }else{
              /* QMap<QString, QVariant> map = result["retour"].toMap();
               qDebug() << "MAP " <<map["Date"].toString();*/

                QString strR = result["retour"].toString();
                QtJson::JsonObject nested = QtJson::parse(strR, ok).toMap();
                qDebug() <<  nested["Date"].toString();
           }



}
