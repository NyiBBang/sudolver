cmake_minimum_required(VERSION 3.5)
project(sudolver)

# Qt
find_package(Qt5Core)
find_package(Qt5Gui)
find_package(Qt5Widgets)
if (Qt5Core_FOUND)
  set(CMAKE_AUTOMOC TRUE)
endif()

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(src)
#add_subdirectory(tests)
