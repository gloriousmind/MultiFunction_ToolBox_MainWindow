#include "controller_database_module.h"

Controller_Database_Module::Controller_Database_Module(QObject *parent)
    : QObject{parent}
{
    workerThread = new QThread(nullptr);
    cur_worker = new Worker_Database_Module(nullptr);
    cur_worker->moveToThread(workerThread);
    connect(workerThread, &QThread::finished, cur_worker, &QObject::deleteLater);
    connect(this, &Controller_Database_Module::connect_for_thread, cur_worker, &Worker_Database_Module::dowork);
    connect(this, &Controller_Database_Module::disconnect_for_thread, cur_worker, &Worker_Database_Module::endwork);
    connect(this, &Controller_Database_Module::update_for_thread, cur_worker, &Worker_Database_Module::updatework);
    workerThread->start();
}

Controller_Database_Module::~Controller_Database_Module()
{
    workerThread->quit();
    workerThread->wait();
}

void Controller_Database_Module::startWork()
{
    emit connect_for_thread();
}

void Controller_Database_Module::endWork()
{
    emit disconnect_for_thread();
}

void Controller_Database_Module::updateWork()
{
    emit update_for_thread();
}



