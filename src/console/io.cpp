#include "io.h"
#include <algorithm>
#include <iterator>
#include <iomanip>

std::ostream& operator<<(std::ostream& os, const grid_value_type& grid)
{
    os << "     1 2 3 4 5 6 7 8 9" << std::endl;
    for (index_type cell = 0; cell < max_cell_index; ++cell)
    {
        if (cell % 27 == 0) os << "    +-----+-----+-----+\n";
        if (cell % 9 == 0) os << "    ";
        if (cell % 3 == 0) os << '|';
        else os << ' ';
        if (grid[cell] == 0) os << ' ';
        else os << grid[cell];
        if (cell % 9 == 8) os << "|\n";
    }
    os << "    +-----+-----+-----+";
    return os;
}

std::istream& operator>>(std::istream& is, grid_value_type& grid)
{
    for (unsigned short i = 0; i < 9*9; ++i)
    {
        std::cin >> grid[i];
        if (!std::cin)
            throw std::ios_base::failure("Could not read grid cell value on input");
    }
    return is;
}

