#ifndef FILESCANNING_MODULE_H
#define FILESCANNING_MODULE_H

#include <QObject>
#include "controller_filescanning_module.h"
#include <QMdiSubWindow>
#include <QTableView>
#include <QStandardItemModel>
#include "myprogressbar.h"

class MyMainWindow;

class FileScanning_Module : public QObject
{
    Q_OBJECT
private:
    friend class MyMainWindow;
public:
    explicit FileScanning_Module(MyMainWindow *window, QObject *parent = nullptr);

private slots:
    void get_scanningdir();
    void start_scanning();
    void end_scanning();
    void display_hide_progressbar();
    void display_hide_scanning_result();
    void receiving_thread_data(QVariantList thread_data);

signals:
    void mdi_subwindow_closed();
private:
    MyMainWindow *main_window;
    QMdiSubWindow *sub_mdi;
    QTableView *data_view;
    QStandardItemModel *data_model;
    int model_row_size = 0;
    MyProgressBar *progress_bar;
    Controller_FileScanning_Module *controller;
    QString received_file_path;
    QString received_file_name;
    QString received_file_size;
    qint64 received_scanned_file_num;
    qint64 received_total_file_num;
};

#endif // FILESCANNING_MODULE_H
