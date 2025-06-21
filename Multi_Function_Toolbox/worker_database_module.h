#ifndef WORKER_DATABASE_MODULE_H
#define WORKER_DATABASE_MODULE_H

#include <QObject>
#include <QVariantList>

class Worker_Database_Module : public QObject
{
    Q_OBJECT
public:
    explicit Worker_Database_Module(QObject *parent = nullptr);

public slots:
    void dowork();
    void endwork();
    void updatework();

signals:
    void connection_status(bool connected);
    void database_data(QVariantList data);

public:
};

#endif // WORKER_DATABASE_MODULE_H
