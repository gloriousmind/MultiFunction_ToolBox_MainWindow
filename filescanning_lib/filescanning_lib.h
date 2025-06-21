#ifndef FILESCANNING_LIB_H
#define FILESCANNING_LIB_H

#include "filescanning_lib_global.h"
#include <QDirIterator>

class FILESCANNING_LIB_EXPORT Filescanning_lib : public QObject
{
    Q_OBJECT
public:
    Filescanning_lib(QObject *parent = nullptr);

public slots:
    void start_filescan(QString path);
    void segment_filescan();
    void end_filescan();

signals:
    void file_scanned(QVariantList file_information);

private:
    QDirIterator *file_scanner_total;
    QDirIterator *file_scanner_info;
    std::atomic<bool> is_scanning = true;
    qlonglong total_file_num = 0;
    qlonglong scanned_file_num = 0;
};

#endif // FILESCANNING_LIB_H
