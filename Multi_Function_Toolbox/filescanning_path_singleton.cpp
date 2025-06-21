#include "filescanning_path_singleton.h"

FileScanning_Path_Singleton* FileScanning_Path_Singleton::_instance = nullptr;

FileScanning_Path_Singleton *FileScanning_Path_Singleton::Instance()
{
    if (_instance == nullptr)
    {
        _instance = new FileScanning_Path_Singleton();
    }
    return _instance;
}

void FileScanning_Path_Singleton::set_scanning_path(QString scanning_path)
{
    if (file_scanning_path.isEmpty() || file_scanning_path != scanning_path)
    {
        file_scanning_path = scanning_path;
    }
}

QString FileScanning_Path_Singleton::get_scanning_path()
{
    return file_scanning_path;
}
