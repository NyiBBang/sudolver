include(../../sudoku.pri)

TEMPLATE = app
TARGET = sudoku_console

LIBS += -llogic

OBJECTS_DIR = $$OBJECTS_DIR/console
MOC_DIR = $$MOC_DIR/console

HEADERS += io.h
SOURCES += io.cpp main.cpp

