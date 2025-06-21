#include "myprogressbar.h"

MyProgressBar::MyProgressBar(QWidget *parent)
    : QWidget{parent}
{
    layout = new QVBoxLayout(this);
    file_information = new QLabel(this);
    progress_inforamation = new QProgressBar(this);
    layout->addWidget(file_information);
    layout->addWidget(progress_inforamation);
}

void MyProgressBar::closeEvent(QCloseEvent *event)
{
    emit closed_by_user();
    QWidget::closeEvent(event);
}
