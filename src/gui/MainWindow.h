#ifndef GUI_MAIN_WINDOW_H
#define GUI_MAIN_WINDOW_H

#include <QtWidgets/QMainWindow>

class FileReader;
class Solver;

class MainWindow : public QMainWindow
{
    public:
        MainWindow(FileReader& reader, Solver& solver, QWidget* parent = 0);

    private:
        void openGridFile();

    private:
        FileReader& reader_;
        Solver& solver_;
};

#endif

