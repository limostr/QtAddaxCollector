#ifndef ROLTECHPOSTE_H
#define ROLTECHPOSTE_H
#include <QObject>
#include <QDebug>

class RoltechPoste: public QObject
{
    Q_OBJECT

public:
    RoltechPoste(QString Poste);
    void decodePoste(QString Poste);

    int getPosteId() const;
    void setPosteId(int newPosteId);

    int getButton1() const;
    void setButton1(int newButton1);

    int getButton2() const;
    void setButton2(int newButton2);

    int getButton3() const;
    void setButton3(int newButton3);

    int getButton4() const;
    void setButton4(int newButton4);

    const QString &getPosteRFID() const;
    void setPosteRFID(const QString &newPosteRFID);

private:
    int PosteId;
    int Button1;
    int Button2;
    int Button3;
    int Button4;
    QString PosteRFID;

};

#endif // ROLTECHPOSTE_H
