#-------------------------------------------------
#
# Project created by QtCreator 2018-07-18T14:29:34
#
#-------------------------------------------------

QT       += core gui\
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test3
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwidget.cpp \
    crashobject.cpp \
    flight.cpp \
    weapon.cpp \
    items.cpp \
    enemyfactory.cpp \
    enemy.cpp \
    bullet.cpp \
    weapon_derived.cpp \
    enemy_derived.cpp \
    bullet_derived.cpp \
    other_items.cpp \
    user.cpp \
    kits.cpp \
    startlogo.cpp \
    bgmthread.cpp \
    gamemenu.cpp \
    gameover.cpp \
    mainmenu.cpp \
    stageclear.cpp \
    windows.cpp

HEADERS += \
        mainwidget.h \
    crashobject.h \
    flight.h \
    weapon.h \
    items.h \
    enemyfactory.h \
    enemy.h \
    bullet.h \
    weapon_derived.h \
    enemy_derived.h \
    bullet_derived.h \
    other_items.h \
    header.h \
    user.h \
    kits.h \
    startlogo.h \
    bgmthread.h \
    gamemenu.h \
    gameover.h \
    mainmenu.h \
    stageclear.h \
    windows.h

FORMS += \
        mainwidget.ui \
    startlogo.ui \
    gamemenu.ui \
    gameover.ui \
    mainmenu.ui \
    stageclear.ui

RESOURCES += \
    resource.qrc

CONFIG += resources_big

RC_ICONS = myico_1.ico
