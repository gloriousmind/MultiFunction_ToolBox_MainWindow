#include "filescanning_lib.h"
#include <QCoreApplication>
#include <QTimer>

Filescanning_lib::Filescanning_lib(QObject *parent) : QObject(parent)
{
}

void Filescanning_lib::start_filescan(QString path)
{
    total_file_num = 0;
    scanned_file_num = 0;
    is_scanning = true;
    file_scanner_total = new QDirIterator(path, QDir::Files, QDirIterator::Subdirectories);
    while (file_scanner_total->hasNext() && is_scanning)
    {
        total_file_num++;
        file_scanner_total->next();
    }
    if (total_file_num == 0)
        return;
    file_scanner_info = new QDirIterator(path, QDir::Files, QDirIterator::Subdirectories);
    QTimer::singleShot(0, this, &Filescanning_lib::segment_filescan);
    return;
}

void Filescanning_lib::segment_filescan()
{
    int cur_cnt = 0;
    int total_cnt = 50;
    while (cur_cnt <= total_cnt && is_scanning && scanned_file_num <= total_file_num)
    {
        cur_cnt++;
        scanned_file_num++;
        QFileInfo cur_Fileinfo = file_scanner_info->nextFileInfo();
        QVariantList cur_file_partInfo;
        cur_file_partInfo << QVariant(cur_Fileinfo.filePath())
                          << QVariant(cur_Fileinfo.fileName())
                          << QVariant(cur_Fileinfo.size())
                          << QVariant(scanned_file_num)
                          << QVariant(total_file_num);
        emit file_scanned(cur_file_partInfo);
    }
    if (is_scanning && scanned_file_num <= total_file_num)
        QTimer::singleShot(0, this, &Filescanning_lib::segment_filescan);
    else
    {
        delete file_scanner_total;
        delete file_scanner_info;
        return;
    }
}

void Filescanning_lib::end_filescan()
{
    is_scanning = false;
}
