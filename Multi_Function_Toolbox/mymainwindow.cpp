#include "mymainwindow.h"
#include "ui_mymainwindow.h"

MyMainWindow::MyMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);
    init_mainwindow();
}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}

bool MyMainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == database_module->sub_mdi && event->type() == QEvent::Close)
    {
        emit database_module->mdi_subwindow_closed();
        return true;
    }
    else if (watched == filescanning_module->sub_mdi && event->type() == QEvent::Close)
    {
        emit filescanning_module->mdi_subwindow_closed();
        return true;
    }
    return false;
}


void MyMainWindow::init_mainwindow()
{
    database_module = new Database_Module(this, this);
    filescanning_module = new FileScanning_Module(this, this);
    return;
}

QMdiArea *MyMainWindow::get_main_window_mdi()
{
    return ui->mdiArea;
}

QAction *MyMainWindow::get_action_connect_to_database()
{
    return ui->action_connect_to_database;
}

QAction *MyMainWindow::get_action_disconnect_to_database()
{
    return ui->action_disconnect_to_database;
}

QAction *MyMainWindow::get_action_update_data()
{
    return ui->action_update_data;
}

QAction *MyMainWindow::get_action_display_data()
{
    return ui->action_display_data;
}

QAction *MyMainWindow::get_action_select_scanning_location()
{
    return ui->action_select_scanning_location;
}

QAction *MyMainWindow::get_action_start_scanning()
{
    return ui->action_start_scanning;
}

QAction *MyMainWindow::get_action_end_scanning()
{
    return ui->action_end_scanning;
}

QAction *MyMainWindow::get_action_display_scanning_progress()
{
    return ui->action_display_scanning_progress;
}

QAction *MyMainWindow::get_action_display_scanning_result()
{
    return ui->action_display_scanning_result;
}




