#include "worker_database_module.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

Worker_Database_Module::Worker_Database_Module(QObject *parent)
    : QObject{parent}
{}

void Worker_Database_Module::dowork()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "myconnection");
    db.setHostName("localhost");
    db.setDatabaseName("QT_DATABASE");
    db.setUserName("root");
    db.setPassword("fengsiqi521");
    if (db.open())
    {
        emit connection_status(true);
        QSqlQuery query(db);
        query.exec("SELECT * FROM computer_science_courses");
        while (query.next())
        {
            QVariantList data;
            data << query.value(0) << query.value(1);
            emit database_data(data);
        }
    }
    else
        emit connection_status(false);
}

void Worker_Database_Module::endwork()
{
    QSqlDatabase::removeDatabase("myconnection");
}

void Worker_Database_Module::updatework()
{
    QSqlDatabase db = QSqlDatabase::database("myconnection");
    QSqlQuery query(db);
    if (!db.transaction())
    {
        qDebug() << "start transaction failure:" << db.lastError().text();
        return;
    }
    if (!query.exec("UPDATE computer_science_courses SET NAME = CONCAT('_', name)"))
    {
        qDebug() << "update failure:" << db.lastError().text();
        db.rollback();
        return;
    }
    if (!db.commit())
    {
        qDebug() << "commit failure:" << db.lastError().text();
        db.rollback();
        return;
    }
    query.exec("SELECT * FROM computer_science_courses");
    while (query.next())
    {
        QVariantList data;
        data << query.value(0) << query.value(1);
        emit database_data(data);
    }
}
