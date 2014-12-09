include(../sudoku.pri)

TEMPLATE = subdirs

SUBDIRS = \
    logic \
    logic_test \
    console \
    gui

console.depends = logic
gui.depends = logic
logic_test.depends = logic

