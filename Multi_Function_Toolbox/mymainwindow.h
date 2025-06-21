#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include "database_module.h"
#include "filescanning_module.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MyMainWindow;
}
QT_END_NAMESPACE

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MyMainWindow(QWidget *parent = nullptr);
    ~MyMainWindow();
    bool eventFilter(QObject *watched, QEvent *event);
    void init_mainwindow();
    QMdiArea* get_main_window_mdi();
    //Database_Module
    QAction* get_action_connect_to_database();
    QAction* get_action_disconnect_to_database();
    QAction* get_action_update_data();
    QAction* get_action_display_data();
    //FielScanning_Module
    QAction* get_action_select_scanning_location();
    QAction* get_action_start_scanning();
    QAction* get_action_end_scanning();
    QAction* get_action_display_scanning_progress();
    QAction* get_action_display_scanning_result();

private:
    Ui::MyMainWindow *ui;
    Database_Module *database_module;
    FileScanning_Module *filescanning_module;
};
#endif // MYMAINWINDOW_H
