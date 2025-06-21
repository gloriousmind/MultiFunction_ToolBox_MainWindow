#ifndef DATABASE_MODULE_H
#define DATABASE_MODULE_H

#include <QObject>
#include "controller_database_module.h"
#include <QTableView>
#include <QStandardItemModel>
#include <QMdiSubWindow>


class MyMainWindow;

class Database_Module : public QObject
{
    Q_OBJECT
private:
    friend class MyMainWindow;
public:
    explicit Database_Module(MyMainWindow *window, QObject *parent = nullptr);

private slots:
    void connect_database();
    void disconnect_database();
    void update_database();
    void handle_connection_status(bool connected);
    void handle_connection_data(QVariantList record);
    void view_display_control();

signals:
    void mdi_subwindow_closed();

private:
    MyMainWindow *main_window;
    QMdiSubWindow *sub_mdi;
    QTableView *data_view;
    QStandardItemModel *data_model;
    int model_row_size = 0;
    Controller_Database_Module *manager;
};

#endif // DATABASE_MODULE_H
