#ifndef ROLTECHRFIDDECODER_H
#define ROLTECHRFIDDECODER_H

#include <QObject>
class RoltechRFIDDecoder: public QObject
{
    Q_OBJECT
public:
     RoltechRFIDDecoder();

     void AppendRecevedTram(QString data);
private slots:
   void decoder(QString Tram);
signals:
    void EndTramEvent(QString Tram);
private:
    QString m_Tram;

};

#endif // ROLTECHRFIDDECODER_H
