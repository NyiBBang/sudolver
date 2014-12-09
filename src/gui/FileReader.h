#ifndef GUI_FILE_READER_H
#define GUI_FILE_READER_H

#include "logic/complex_types.h"

class QFile;

class FileReader
{
    public:
        FileReader(const grid_entity_type& grid);

    public:
        void read(QFile& file);

    private:
        grid_entity_type grid_;
};

#endif

