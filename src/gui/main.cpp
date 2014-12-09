#include "FileReader.h"
#include "MainWindow.h"
#include "GridView.h"
#include "GridModel.h"
#include "logic/Solver.h"
#include "logic/SolvingStepper.h"
#include "logic/Registries.h"
#include "logic/HeuristicsConstraints.h"
#include "logic/Validator.h"
#include "logic/ChangesChecker.h"
#include "logic/StateSaver.h"
#include "logic/HypothesisMaker.h"
#include "logic/BacktrackReasons.h"
#include "logic/complex_types.h"
#include <QtWidgets/QApplication>
#include <string>
#include <iostream>

int main(int argc, char** argv)
{
    try
    {
        QApplication app(argc, argv);

        // Logic Initialization
        grid_entity_type grid(new grid_value_type());
        possibilities_type poss;
        combinations_type combinations;
        Registries registry(poss, combinations);
        HeuristicsConstraints heuristics(grid, registry);
        Validator validator(grid);
        ChangesChecker checker(grid, poss);
        stack_type stack;
        StateSaver stateSaver(grid, combinations, stack);
        BacktrackReasons reasons(validator, grid, registry, registry);
        HypothesisMaker hypomaker(grid, registry, stateSaver, registry);
        hypomaker.addReason(reasons);
        Solver solver(validator, checker, hypomaker, hypomaker);
        SolvingStepper stepper(heuristics);
        solver.suscribe(stepper);

        // Gui Initialization
        FileReader reader(grid);
        MainWindow mw(reader, solver);

        GridView* view = new GridView(validator);
        mw.setCentralWidget(view);

        GridModel* model = new GridModel(grid, view);
        view->setModel(model);
        solver.suscribe(*model);

        mw.show();
        return app.exec();
    }
    catch (const std::exception& ex)
    {
        std::cerr << "ERROR: " << ex.what() << std::endl;
        return -1;
    }
}

