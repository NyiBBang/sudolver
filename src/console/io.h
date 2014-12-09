#ifndef CONSOLE_IO_H
#define CONSOLE_IO_H

#include "logic/complex_types.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const grid_value_type& grid);
std::istream& operator>>(std::istream& is, grid_value_type& grid);

#endif

