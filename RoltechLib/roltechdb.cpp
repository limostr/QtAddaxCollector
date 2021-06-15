#include "roltechdb.h"

RoltechDB::RoltechDB()
{
    QSqlDatabase db= QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("tmproltechsystem");
    db.setPort(3307);
    db.setUserName("root");
    db.setPassword("");
    if(db.open()){

    }

   /* m_Conexion= new QSqlDatabase();
        m_Conexion->addDatabase("QMYSQL");
        m_Conexion->setHostName("localhost");
        m_Conexion->setDatabaseName("tmproltechsystem");
        m_Conexion->setPort(3307);
        m_Conexion->setUserName("root");
        m_Conexion->setPassword("");
        if(m_Conexion->open()){

        }*/
}
