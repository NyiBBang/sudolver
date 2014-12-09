include(../../sudoku.pri)

TEMPLATE = app
TARGET = sudoku_gui
QT += core widgets gui
CONFIG += qt

LIBS += -llogic

OBJECTS_DIR = $$OBJECTS_DIR/gui
MOC_DIR = $$MOC_DIR/gui

HEADERS += *.h
SOURCES += *.cpp

