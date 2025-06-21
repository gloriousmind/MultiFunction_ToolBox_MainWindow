/********************************************************************************
** Form generated from reading UI file 'mymainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYMAINWINDOW_H
#define UI_MYMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyMainWindow
{
public:
    QAction *action_connect_to_database;
    QAction *action_disconnect_to_database;
    QAction *action_update_data;
    QAction *action_display_data;
    QAction *action_select_scanning_location;
    QAction *action_start_scanning;
    QAction *action_end_scanning;
    QAction *action_display_scanning_progress;
    QAction *action_display_scanning_result;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QMdiArea *mdiArea;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MyMainWindow)
    {
        if (MyMainWindow->objectName().isEmpty())
            MyMainWindow->setObjectName("MyMainWindow");
        MyMainWindow->resize(800, 600);
        action_connect_to_database = new QAction(MyMainWindow);
        action_connect_to_database->setObjectName("action_connect_to_database");
        action_disconnect_to_database = new QAction(MyMainWindow);
        action_disconnect_to_database->setObjectName("action_disconnect_to_database");
        action_update_data = new QAction(MyMainWindow);
        action_update_data->setObjectName("action_update_data");
        action_display_data = new QAction(MyMainWindow);
        action_display_data->setObjectName("action_display_data");
        action_select_scanning_location = new QAction(MyMainWindow);
        action_select_scanning_location->setObjectName("action_select_scanning_location");
        action_start_scanning = new QAction(MyMainWindow);
        action_start_scanning->setObjectName("action_start_scanning");
        action_end_scanning = new QAction(MyMainWindow);
        action_end_scanning->setObjectName("action_end_scanning");
        action_display_scanning_progress = new QAction(MyMainWindow);
        action_display_scanning_progress->setObjectName("action_display_scanning_progress");
        action_display_scanning_result = new QAction(MyMainWindow);
        action_display_scanning_result->setObjectName("action_display_scanning_result");
        centralwidget = new QWidget(MyMainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName("mdiArea");

        gridLayout->addWidget(mdiArea, 0, 0, 1, 1);

        MyMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MyMainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 27));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        MyMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MyMainWindow);
        statusbar->setObjectName("statusbar");
        MyMainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(action_connect_to_database);
        menu->addAction(action_disconnect_to_database);
        menu->addAction(action_update_data);
        menu->addAction(action_display_data);
        menu_2->addAction(action_select_scanning_location);
        menu_2->addAction(action_start_scanning);
        menu_2->addAction(action_end_scanning);
        menu_2->addAction(action_display_scanning_progress);
        menu_2->addAction(action_display_scanning_result);

        retranslateUi(MyMainWindow);

        QMetaObject::connectSlotsByName(MyMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MyMainWindow)
    {
        MyMainWindow->setWindowTitle(QCoreApplication::translate("MyMainWindow", "MyMainWindow", nullptr));
        action_connect_to_database->setText(QCoreApplication::translate("MyMainWindow", "\350\277\236\346\216\245\346\225\260\346\215\256\345\272\223", nullptr));
        action_disconnect_to_database->setText(QCoreApplication::translate("MyMainWindow", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        action_update_data->setText(QCoreApplication::translate("MyMainWindow", "\346\233\264\346\224\271\346\225\260\346\215\256", nullptr));
        action_display_data->setText(QCoreApplication::translate("MyMainWindow", "\346\230\276\347\244\272\346\225\260\346\215\256", nullptr));
        action_select_scanning_location->setText(QCoreApplication::translate("MyMainWindow", "\351\200\211\346\213\251\346\211\253\346\217\217\344\275\215\347\275\256", nullptr));
        action_start_scanning->setText(QCoreApplication::translate("MyMainWindow", "\345\274\200\345\247\213\346\211\253\346\217\217", nullptr));
        action_end_scanning->setText(QCoreApplication::translate("MyMainWindow", "\347\273\210\346\255\242\346\211\253\346\217\217", nullptr));
        action_display_scanning_progress->setText(QCoreApplication::translate("MyMainWindow", "\346\230\276\347\244\272\346\211\253\346\217\217\350\277\233\345\272\246", nullptr));
        action_display_scanning_result->setText(QCoreApplication::translate("MyMainWindow", "\346\230\276\347\244\272\346\211\253\346\217\217\347\273\223\346\236\234", nullptr));
        menu->setTitle(QCoreApplication::translate("MyMainWindow", "\346\225\260\346\215\256\345\272\223", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MyMainWindow", "\346\226\207\344\273\266\346\211\253\346\217\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyMainWindow: public Ui_MyMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMAINWINDOW_H
