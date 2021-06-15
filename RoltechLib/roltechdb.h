#ifndef ROLTECHDB_H
#define ROLTECHDB_H
#include <QObject>
#include <QDebug>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
class RoltechDB: public QObject
{
    Q_OBJECT
public:
    RoltechDB();
private :
    QSqlDatabase *m_Conexion;
};

#endif // ROLTECHDB_H
