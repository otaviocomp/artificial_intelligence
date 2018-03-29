QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TicTacToe
TEMPLATE = app


SOURCES += main.cpp\
        game.cpp \
    board.cpp \
    minmax.cpp

HEADERS  += game.h \
    ai.h \
    board.h \
    globals.h \
    minmax.h

RESOURCES += \
    resource.qrc
