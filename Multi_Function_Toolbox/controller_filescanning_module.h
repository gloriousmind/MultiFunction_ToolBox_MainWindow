#ifndef CONTROLLER_FILESCANNING_MODULE_H
#define CONTROLLER_FILESCANNING_MODULE_H

#include <QObject>
#include <QThread>
#include "../filescanning_lib/filescanning_lib.h"

class FileScanning_Module;

class Controller_FileScanning_Module : public QObject
{
    Q_OBJECT
private:
    friend class FileScanning_Module;
public:
    explicit Controller_FileScanning_Module(QObject *parent = nullptr);
    ~Controller_FileScanning_Module();
    void start_scanning_work();
    void end_scanning_work();

signals:
    void thread_start_scanning_work(QString scanning_path);
    void thread_end_scanning_work();
private slots:

private:
    Filescanning_lib *worker;
    QThread *thread;
};

#endif // CONTROLLER_FILESCANNING_MODULE_H
