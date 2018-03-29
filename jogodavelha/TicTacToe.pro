QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TicTacToe
TEMPLATE = app


SOURCES += main.cpp\
        game.cpp \
    board.cpp \
    minmax.cpp \
    menu.cpp \
    inicia.cpp

HEADERS  += game.h \
    ai.h \
    board.h \
    globals.h \
    minmax.h \
    menu.h \
    inicia.h

RESOURCES += \
    resource.qrc

FORMS += \
    menu.ui \
    inicia.ui
