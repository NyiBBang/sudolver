add_executable(sudolver-cli
  main.cpp
  io.h io.cpp
)
target_link_libraries(sudolver-cli sudolver-logic)
