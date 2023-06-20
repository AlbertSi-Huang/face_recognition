QT       += core gui webenginewidgets
#视频播放需要pro文件加入以下模块
QT += texttospeech

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
#可以在项目中使用预编译头文件的支持


QMAKE_CXXFLAGS += /utf-8

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += $$PWD/module/algorithm
include($$PWD/module/algorithm/algorithm.pri)
UI_DIR=./

SOURCES += \
    DateTimeHelper.cpp \
    FileCommonHelper.cpp \
    MyPlaySoundThread.cpp \
    PageControl.cpp \
    QXVideoDetectWidget.cpp \
    QXVideoWidget.cpp \
    XFaceDetectThread.cpp \
    XVideoDetectThread.cpp \
    XVideoThread.cpp \
    chelmettip.cpp \
    config_file.cpp \
    main.cpp \
    mainwindow.cpp \
    sqlite_record.cpp \
    sqlite_white.cpp \
    tablewidgetpage.cpp \
    xinitthread.cpp

HEADERS += \
    DateTimeHelper.h \
    FileCommonHelper.h \
    MyPlaySoundThread.h \
    PageControl.h \
    QXVideoDetectWidget.h \
    QXVideoWidget.h \
    XFaceDetectThread.h \
    XVideoDetectThread.h \
    XVideoThread.h \
    chelmettip.h \
    config_file.h \
    mainwindow.h \
    sqlite_record.h \
    sqlite_white.h \
    tablewidgetpage.h \
    xinitthread.h

FORMS += \
    HelmetTip.ui \
    TablePage.ui \
    chelmettip.ui \
    mainwindow.ui \
    tablewidgetpage.ui

INCLUDEPATH += $$PWD/include/Opencv

#LIBS += -L$$PWD/lib/ -lopencv_world453d

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix|win32: LIBS += -L$$PWD/lib/ -lFaceSDK

INCLUDEPATH += $$PWD/include/face_alg
DEPENDPATH += $$PWD/include/face_alg

DISTFILES +=

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lsqlite3
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lsqlite3

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lopencv_world453
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lopencv_world453d

INCLUDEPATH += $$PWD/include/Opencv
DEPENDPATH += $$PWD/include/Opencv

win32: LIBS += -L$$PWD/lib/ -lCoatSdk

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

win32: LIBS += -L$$PWD/lib/ -lHelmetSdk

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include
