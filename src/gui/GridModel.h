#ifndef GUI_GRID_MODEL_H
#define GUI_GRID_MODEL_H

#include "logic/IStepper.h"
#include "logic/complex_types.h"
#include <QtCore/QAbstractTableModel>

class GridModel : public QAbstractTableModel
                , public IStepper
{
    Q_OBJECT

    public:
        GridModel(const grid_entity_type& grid, QObject* parent = 0);

    public:
        virtual int rowCount(const QModelIndex& parent = QModelIndex()) const;
        virtual int columnCount(const QModelIndex& parent = QModelIndex()) const;
        virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
        virtual void step();

    private:
        grid_entity_type grid_;
};

#endif

