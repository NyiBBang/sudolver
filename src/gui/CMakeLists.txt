add_executable(sudolver-gui
  FileReader.cpp FileReader.h
  GridModel.cpp GridModel.h
  GridView.cpp GridView.h
  MainWindow.cpp MainWindow.h
  main.cpp
)
target_link_libraries(sudolver-gui sudolver-logic Qt5::Core Qt5::Gui Qt5::Widgets)
