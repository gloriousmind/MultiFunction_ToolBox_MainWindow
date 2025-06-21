#ifndef CONTROLLER_DATABASE_MODULE_H
#define CONTROLLER_DATABASE_MODULE_H

#include <QObject>
#include "worker_database_module.h"
#include <QThread>

class Controller_Database_Module : public QObject
{
    Q_OBJECT
public:
    explicit Controller_Database_Module(QObject *parent = nullptr);
    ~Controller_Database_Module();
    void startWork();
    void endWork();
    void updateWork();

signals:
    void connect_for_thread();
    void disconnect_for_thread();
    void update_for_thread();

public:
    Worker_Database_Module *cur_worker;
    QThread *workerThread;
};

#endif // CONTROLLER_DATABASE_MODULE_H
