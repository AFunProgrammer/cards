QT       += core gui openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets svg

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ccarddeck.cpp \
    cunocard.cpp \
    cunogame.cpp \
    cunoplayer.cpp \
    main.cpp \
    mainwindow.cpp \
    qdrawcards.cpp \
    qimagebox.cpp

HEADERS += \
    ccarddeck.h \
    cunocard.h \
    cunogame.h \
    cunoplayer.h \
    mainwindow.h \
    qdrawcards.h \
    qimagebox.h \
    utility.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
