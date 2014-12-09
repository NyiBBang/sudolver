include(../../sudoku.pri)

TEMPLATE = app
TARGET = logic_test

LIBS += -llogic -lboost_unit_test_framework

OBJECTS_DIR = $$OBJECTS_DIR/logic_test
MOC_DIR = $$MOC_DIR/logic_test

HEADERS += *.h
SOURCES += *.cpp
