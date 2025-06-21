#include "controller_filescanning_module.h"
#include "filescanning_path_singleton.h"

Controller_FileScanning_Module::Controller_FileScanning_Module(QObject *parent)
    : QObject{parent}
{
    worker = new Filescanning_lib();
    thread = new QThread(this);
    worker->moveToThread(thread);
    connect(thread, &QThread::finished, worker, &QObject::deleteLater);
    connect(this, &Controller_FileScanning_Module::thread_start_scanning_work, worker, &Filescanning_lib::start_filescan);
    connect(this, &Controller_FileScanning_Module::thread_end_scanning_work, worker, &Filescanning_lib::end_filescan);
    thread->start();
}

Controller_FileScanning_Module::~Controller_FileScanning_Module()
{
    thread->quit();
    thread->wait();
}

void Controller_FileScanning_Module::start_scanning_work()
{
    emit thread_start_scanning_work(FileScanning_Path_Singleton::Instance()->get_scanning_path());
}

void Controller_FileScanning_Module::end_scanning_work()
{
    emit thread_end_scanning_work();
}
