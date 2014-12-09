#include "MainWindow.h"
#include "FileReader.h"
#include "logic/Solver.h"
#include <QtWidgets/QLayout>
#include <QtWidgets/QMenuBar>
#include <QtCore/QCoreApplication>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>
#include <stdexcept>

MainWindow::MainWindow(FileReader& reader, Solver& solver, QWidget* parent)
    : QMainWindow(parent)
    , reader_(reader)
    , solver_(solver)
{
    layout()->setSizeConstraint(QLayout::SetFixedSize);

    QMenu* fileMenu = menuBar()->addMenu("&File");

    QAction* openAction = fileMenu->addAction("&Open");
    connect(openAction, &QAction::triggered, this, &MainWindow::openGridFile);

    QAction* quitAction = fileMenu->addAction("&Quit");
    connect(quitAction, &QAction::triggered, &QCoreApplication::quit);

    QMenu* toolsMenu = menuBar()->addMenu("&Tools");

    QAction* solveAction = toolsMenu->addAction("&Solve");
    connect(solveAction, &QAction::triggered, [this](){ solver_.run();});
}

void MainWindow::openGridFile()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open grid file", QString(), QString(), 0, QFileDialog::ReadOnly);
    if (filename.isEmpty()) return;

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;

    try
    {
        reader_.read(file);
    }
    catch (const std::exception& ex)
    {
        QMessageBox::critical(this, "Error while reading file", "An error occurred while reading the file."
                                    "It might be invalid, please check it.\nError: " + QString::fromStdString(ex.what()));
    }
}

