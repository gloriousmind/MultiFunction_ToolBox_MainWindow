#ifndef MYPROGRESSBAR_H
#define MYPROGRESSBAR_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QProgressBar>

class FileScanning_Module;

class MyProgressBar : public QWidget
{
    Q_OBJECT
private:
    friend class FileScanning_Module;
public:
    explicit MyProgressBar(QWidget *parent = nullptr);
protected:
    void closeEvent(QCloseEvent *event);
signals:
    void closed_by_user();
private:
    QVBoxLayout *layout;
    QLabel *file_information;
    QProgressBar *progress_inforamation;
};

#endif // MYPROGRESSBAR_H

