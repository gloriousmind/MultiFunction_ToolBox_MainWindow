#include "filescanning_module.h"
#include "mymainwindow.h"
#include <QMdiArea>
#include <QFileDialog>
#include "filescanning_path_singleton.h"

FileScanning_Module::FileScanning_Module(MyMainWindow *window, QObject *parent) :
    QObject(parent), main_window(window)
{
    sub_mdi = new QMdiSubWindow;
    sub_mdi->hide();
    controller = new Controller_FileScanning_Module(this);
    data_model = new QStandardItemModel(this);
    data_view = new QTableView();
    sub_mdi->setWidget(data_view);
    main_window->get_main_window_mdi()->addSubWindow(sub_mdi);
    main_window->get_action_start_scanning()->setEnabled(false);
    main_window->get_action_end_scanning()->setEnabled(false);
    main_window->get_action_display_scanning_progress()->setEnabled(false);
    main_window->get_action_display_scanning_result()->setEnabled(false);
    connect(main_window->get_action_select_scanning_location(), &QAction::triggered, this, &FileScanning_Module::get_scanningdir);
    connect(main_window->get_action_start_scanning(), &QAction::triggered, this, &FileScanning_Module::start_scanning);
    connect(main_window->get_action_end_scanning(), &QAction::triggered, this, &FileScanning_Module::end_scanning);
    connect(main_window->get_action_display_scanning_progress(), &QAction::triggered, this, &FileScanning_Module::display_hide_progressbar);
    connect(main_window->get_action_display_scanning_result(), &QAction::triggered, this, &FileScanning_Module::display_hide_scanning_result);
}

void FileScanning_Module::get_scanningdir()
{
    main_window->get_action_display_scanning_result()->setText("显示扫描结果");
    sub_mdi->hide();
    if (data_model != nullptr)
    {
        delete data_model;
    }
    data_model = new QStandardItemModel(this);
    model_row_size = 0;
    QString dir_to_scan = QFileDialog::getExistingDirectory(nullptr, "选择扫描文件夹", "/home");
    FileScanning_Path_Singleton * local_instance = FileScanning_Path_Singleton::Instance();
    local_instance->set_scanning_path(dir_to_scan);
    sub_mdi->installEventFilter(main_window);
    connect(this, &FileScanning_Module::mdi_subwindow_closed, this, &FileScanning_Module::display_hide_scanning_result, Qt::UniqueConnection);
    progress_bar = new MyProgressBar();
    progress_bar->progress_inforamation->setMaximum(100);
    progress_bar->progress_inforamation->setMinimum(0);
    connect(progress_bar, &MyProgressBar::closed_by_user, this, &FileScanning_Module::display_hide_progressbar, Qt::UniqueConnection);
    connect(controller->worker, &Filescanning_lib::file_scanned, this, &FileScanning_Module::receiving_thread_data, Qt::UniqueConnection);
    main_window->get_action_start_scanning()->setEnabled(true);
    main_window->get_action_end_scanning()->setEnabled(true);
    main_window->get_action_display_scanning_progress()->setEnabled(true);
    main_window->get_action_display_scanning_result()->setEnabled(true);
}

void FileScanning_Module::start_scanning()
{
    controller->start_scanning_work();
    progress_bar->show();
    main_window->get_action_display_scanning_progress()->setText("隐藏扫描进度");
    main_window->get_action_display_scanning_result()->setEnabled(false);
}

void FileScanning_Module::end_scanning()
{
    controller->end_scanning_work();
    main_window->get_action_start_scanning()->setEnabled(false);
    main_window->get_action_end_scanning()->setEnabled(false);
    main_window->get_action_display_scanning_result()->setEnabled(true);
}

void FileScanning_Module::display_hide_progressbar()
{
    if (main_window->get_action_display_scanning_progress()->text() == "显示扫描进度")
    {
        progress_bar->show();
        main_window->get_action_display_scanning_progress()->setText("隐藏扫描进度");
    }
    else
    {
        progress_bar->hide();
        main_window->get_action_display_scanning_progress()->setText("显示扫描进度");
    }
}

void FileScanning_Module::display_hide_scanning_result()
{
    if (main_window->get_action_display_scanning_result()->text() == "显示扫描结果")
    {
        data_view->setModel(data_model);
        data_view->resizeColumnsToContents();
        main_window->get_action_display_scanning_result()->setText("隐藏扫描结果");
        sub_mdi->show();
    }
    else
    {
        data_view->setModel(nullptr);
        main_window->get_action_display_scanning_result()->setText("显示扫描结果");
        sub_mdi->hide();
    }
}

void FileScanning_Module::receiving_thread_data(QVariantList thread_data)
{
    received_file_path = thread_data[0].toString();
    received_file_name = thread_data[1].toString();
    received_file_size = thread_data[2].toString();
    received_scanned_file_num = thread_data[3].toLongLong();
    received_total_file_num = thread_data[4].toLongLong();
    data_model->insertRow(model_row_size);
    QStandardItem *row_data1 = new QStandardItem(received_file_name);
    QStandardItem *row_data2 = new QStandardItem(received_file_size);
    data_model->setItem(model_row_size, 0, row_data1);
    data_model->setItem(model_row_size, 1, row_data2);
    data_model->setHeaderData(0, Qt::Horizontal, QVariant(QString("file name")));
    data_model->setHeaderData(1, Qt::Horizontal, QVariant(QString("size in bytes")));
    model_row_size++;
    progress_bar->file_information->setText(QString(received_file_path));
    progress_bar->progress_inforamation->setValue(100 * received_scanned_file_num / received_total_file_num);
    if (progress_bar->progress_inforamation->value() == 100)
    {
        main_window->get_action_display_scanning_result()->setEnabled(true);
        main_window->get_action_start_scanning()->setEnabled(false);
        main_window->get_action_end_scanning()->setEnabled(false);
    }
    progress_bar->update();
}


