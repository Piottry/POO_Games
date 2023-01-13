QT       += core gui \
multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bullet.cpp \
    centre_logistique.cpp \
    enemy.cpp \
    hud.cpp \
    ia.cpp \
    main.cpp \
    mainwindow.cpp \
    mur.cpp \
    mygame.cpp \
    newpop.cpp \
    notagame.cpp \
    player.cpp

HEADERS += \
    bullet.h \
    centre_logistique.h \
    enemy.h \
    hud.h \
    ia.h \
    mainwindow.h \
    mur.h \
    mygame.h \
    newpop.h \
    notagame.h \
    player.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
