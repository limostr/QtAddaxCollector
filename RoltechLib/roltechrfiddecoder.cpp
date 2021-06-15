#include "roltechrfiddecoder.h"
#include "roltechposte.h"

RoltechRFIDDecoder::RoltechRFIDDecoder()
{
    connect(this,SIGNAL(EndTramEvent(QString)),this,SLOT(decoder(QString)));
    this->m_Tram="";
}

void RoltechRFIDDecoder::decoder(QString Tram)
{
    qDebug() << "TRAM To decode " << Tram;
    QStringList LesPoste=Tram.split(',');
    foreach(QString LePoste,LesPoste){
        if(LePoste[0]!='S' && LePoste[0]!='F'){
             RoltechPoste Poste(LePoste);
        }

    }

}

void RoltechRFIDDecoder::AppendRecevedTram(QString data)
{
    int BeginTram=data.indexOf('S');
    int EndTram=data.indexOf('F');
    if(BeginTram!=-1 && EndTram!=-1){
        int longeur=EndTram-BeginTram;
        if(longeur<0){
            this->m_Tram+=data.mid(0,EndTram+1);
            emit EndTramEvent(this->m_Tram);
            this->m_Tram=data.mid(BeginTram);
        }else if(longeur>0){
            this->m_Tram+=data.mid(BeginTram,longeur+1);
            emit EndTramEvent(this->m_Tram);
            this->m_Tram=data.mid(EndTram);
        }
    }else if(BeginTram==-1 && EndTram!=-1){
        this->m_Tram+=data.mid(0,EndTram+1);
        emit EndTramEvent(this->m_Tram);
        this->m_Tram="";
    }else if(BeginTram!=-1 && EndTram==-1){
        this->m_Tram+=data;
    }else{
        this->m_Tram+=data;
    }
}
