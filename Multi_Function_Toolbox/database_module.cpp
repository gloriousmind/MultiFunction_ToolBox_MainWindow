#include "database_module.h"
#include "mymainwindow.h"
#include "ui_mymainwindow.h"
#include <QMessageBox>
#include <QHeaderView>

Database_Module::Database_Module(MyMainWindow *window, QObject *parent)
    : QObject{parent}, main_window(window)
{
    sub_mdi = new QMdiSubWindow;
    sub_mdi->hide();
    data_model = new QStandardItemModel(this);
    data_view = new QTableView();
    sub_mdi->setWidget(data_view);
    main_window->get_main_window_mdi()->addSubWindow(sub_mdi);
    main_window->get_action_update_data()->setEnabled(false);
    connect(main_window->get_action_connect_to_database(), &QAction::triggered, this, &Database_Module::connect_database);
    connect(main_window->get_action_disconnect_to_database(), &QAction::triggered, this, &Database_Module::disconnect_database);
    connect(main_window->get_action_display_data(), &QAction::triggered, this, &Database_Module::view_display_control);
    connect(main_window->get_action_update_data(), &QAction::triggered, this, &Database_Module::update_database);
}

void Database_Module::connect_database()
{
    data_view->setModel(nullptr);
    data_model->clear();
    model_row_size = 0;
    main_window->get_action_display_data()->setText("显示数据");
    manager = new Controller_Database_Module(this);
    sub_mdi->installEventFilter(main_window);
    connect(this, &Database_Module::mdi_subwindow_closed, this, &Database_Module::view_display_control, Qt::UniqueConnection);
    connect(manager->cur_worker, &Worker_Database_Module::connection_status, this, &Database_Module::handle_connection_status, Qt::UniqueConnection);
    connect(manager->cur_worker, &Worker_Database_Module::database_data, this, &Database_Module::handle_connection_data, Qt::UniqueConnection);
    manager->startWork();
}

void Database_Module::disconnect_database()
{
    main_window->get_action_update_data()->setEnabled(false);
    main_window->get_action_connect_to_database()->setEnabled(true);
    manager->endWork();  
}

void Database_Module::update_database()
{
    data_view->setModel(nullptr);
    data_model->clear();
    model_row_size = 0;
    main_window->get_action_display_data()->setText("显示数据");
    manager->updateWork();
}

void Database_Module::handle_connection_status(bool connected)
{
    if (connected)
    {
        QMessageBox::information(main_window, "连接状态", "数据库连接成功!");
        main_window->get_action_update_data()->setEnabled(true);
        main_window->get_action_connect_to_database()->setEnabled(false);
    }
    else
    {
        QMessageBox::information(main_window, "连接状态", "数据库连接失败!");
        main_window->get_action_display_data()->setEnabled(false);
    }
}

void Database_Module::handle_connection_data(QVariantList record)
{
    data_model->insertRow(model_row_size++);
    data_view->verticalHeader()->setVisible(false);
    int column = 0;
    for (QVariant &value : record)
    {
        QStandardItem *item = new QStandardItem(value.toString());
        data_model->setItem(model_row_size - 1, column++, item);
    }
}

void Database_Module::view_display_control()
{
    if (main_window->get_action_display_data()->text() == "显示数据")
    {
        data_view->setModel(data_model);
        data_view->resizeColumnsToContents();
        main_window->get_action_display_data()->setText("隐藏显示");
        sub_mdi->show();
    }
    else
    {
        data_view->setModel(nullptr);
        main_window->get_action_display_data()->setText("显示数据");
        sub_mdi->hide();
    }
}
