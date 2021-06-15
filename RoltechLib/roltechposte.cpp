#include "roltechposte.h"
    #include <QException>
RoltechPoste::RoltechPoste(QString Poste)
{
    this->decodePoste(Poste);
}

void RoltechPoste::decodePoste(QString Poste)
{
    try {
        QStringList list = Poste.split(";");
        QString RPosteId=list.at(0);
        QString RPosteRFID=list.at(1);
        QString RButtonListe=list.at(2);

        this->PosteId= RPosteId.split(":").at(1).toInt();
        this->PosteRFID=RPosteRFID;

        this->Button1=RButtonListe[0].digitValue();
        this->Button2=RButtonListe[1].digitValue();
        this->Button3=RButtonListe[2].digitValue();
        this->Button4=RButtonListe[3].digitValue();

        qDebug() << "Poste id:" << this->PosteId << "Poste:" <<this->PosteRFID <<"button 1" <<this->Button1 <<"button 2" <<this->Button2 <<"button 3" <<this->Button3 <<"button 4" <<this->Button4;

        }catch(QException &Exp)
        {
            qDebug() << "something went wrong";
        }

}

int RoltechPoste::getPosteId() const
{
    return PosteId;
}

void RoltechPoste::setPosteId(int newPosteId)
{
    PosteId = newPosteId;
}

int RoltechPoste::getButton1() const
{
    return Button1;
}

void RoltechPoste::setButton1(int newButton1)
{
    Button1 = newButton1;
}

int RoltechPoste::getButton2() const
{
    return Button2;
}

void RoltechPoste::setButton2(int newButton2)
{
    Button2 = newButton2;
}

int RoltechPoste::getButton3() const
{
    return Button3;
}

void RoltechPoste::setButton3(int newButton3)
{
    Button3 = newButton3;
}

int RoltechPoste::getButton4() const
{
    return Button4;
}

void RoltechPoste::setButton4(int newButton4)
{
    Button4 = newButton4;
}

const QString &RoltechPoste::getPosteRFID() const
{
    return PosteRFID;
}

void RoltechPoste::setPosteRFID(const QString &newPosteRFID)
{
    PosteRFID = newPosteRFID;
}
