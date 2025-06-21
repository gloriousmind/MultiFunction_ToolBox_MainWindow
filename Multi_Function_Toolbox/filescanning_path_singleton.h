#ifndef FILESCANNING_PATH_SINGLETON_H
#define FILESCANNING_PATH_SINGLETON_H

#include <QObject>

class FileScanning_Path_Singleton : public QObject
{
    Q_OBJECT
public:
    static FileScanning_Path_Singleton* Instance();
    void set_scanning_path(QString scanning_path);
    QString get_scanning_path();
protected:
    explicit FileScanning_Path_Singleton(QObject *parent = nullptr)
        : QObject{parent}
    {}

signals:

private:
    QString file_scanning_path = "";
    static FileScanning_Path_Singleton* _instance;
};

#endif // FILESCANNING_PATH_SINGLETON_H
