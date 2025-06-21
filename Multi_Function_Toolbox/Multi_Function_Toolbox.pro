QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller_database_module.cpp \
    controller_filescanning_module.cpp \
    database_module.cpp \
    filescanning_module.cpp \
    filescanning_path_singleton.cpp \
    main.cpp \
    mymainwindow.cpp \
    myprogressbar.cpp \
    worker_database_module.cpp

HEADERS += \
    ../filescanning_lib/filescanning_lib.h \
    controller_database_module.h \
    controller_filescanning_module.h \
    database_module.h \
    filescanning_module.h \
    filescanning_path_singleton.h \
    mymainwindow.h \
    myprogressbar.h \
    worker_database_module.h

FORMS += \
    mymainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../filescanning_lib/build/Desktop_Qt_6_8_3-Debug/release/ -lfilescanning_lib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../filescanning_lib/build/Desktop_Qt_6_8_3-Debug/debug/ -lfilescanning_lib
else:unix: LIBS += -L$$PWD/../filescanning_lib/build/Desktop_Qt_6_8_3-Debug/ -lfilescanning_lib

INCLUDEPATH += $$PWD/../filescanning_lib/build/Desktop_Qt_6_8_3-Debug
DEPENDPATH += $$PWD/../filescanning_lib/build/Desktop_Qt_6_8_3-Debug
