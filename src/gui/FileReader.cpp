#include "FileReader.h"
#include <QtCore/QFile>
#include <QtCore/QTextStream>

FileReader::FileReader(const grid_entity_type& grid)
    : grid_(grid)
{
    if (!grid_) throw std::runtime_error("Invalid grid entity");
}

void FileReader::read(QFile& file)
{
    QTextStream in(&file);
    for (unsigned short i = 0; i < 9*9; ++i)
    {
        if (in.atEnd())
            throw std::runtime_error("Could not read all values from file");
        in >> (*grid_)[i];
        if (in.status() != QTextStream::Ok)
            throw std::runtime_error("Invalid grid file");
    }
}

