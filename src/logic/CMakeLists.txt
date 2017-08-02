add_library(sudolver-logic
  BacktrackReasons.cpp BacktrackReasons.h
  basic_static_data.h basic_types.h
  ChangesChecker.cpp ChangesChecker.h
  complex_static_data.cpp complex_static_data.h
  complex_types.cpp complex_types.h
  conversion.cpp conversion.h
  FilledCellNoPossibilityConstraint.cpp FilledCellNoPossibilityConstraint.h
  HeuristicsConstraints.cpp HeuristicsConstraints.h
  HypothesisMaker.cpp HypothesisMaker.h
  IApplyable.h
  IBacktracker.h
  IBacktrackReason.h
  IChangesChecker.h
  ICombinationsRegistry.h
  IHypothesisMaker.h
  IPossibilitiesRegistry.h
  IStateSaver.h
  IStepper.h
  IValidator.h
  Registries.cpp Registries.h
  Solver.cpp Solver.h
  SolvingStepper.cpp SolvingStepper.h
  StateSaver.cpp StateSaver.h
  UniquePossibilityInCellHeuristic.cpp UniquePossibilityInCellHeuristic.h
  UniquePossibilityInElementHeuristic.cpp UniquePossibilityInElementHeuristic.h
  UniqueValueInElementConstraint.cpp UniqueValueInElementConstraint.h
  Validator.cpp Validator.h
  WholeDomainFiller.cpp WholeDomainFiller.h
)
