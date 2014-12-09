#include "GridModel.h"
#include <QtWidgets/QApplication>

GridModel::GridModel(const grid_entity_type& grid, QObject* parent)
    : QAbstractTableModel(parent)
    , grid_(grid)
{
}

int GridModel::rowCount(const QModelIndex& parent) const
{
    return parent.isValid() ? 0 : 9;
}

int GridModel::columnCount(const QModelIndex& parent) const
{
    return parent.isValid() ? 0 : 9;
}

QVariant GridModel::data(const QModelIndex& index, int role) const
{
    const int row = index.row();
    const int col = index.column();

    if (row < 0 or row >= 9 or col < 0 or col >= 9)
        return QVariant();

    const value_type value = (*grid_)[row * 9 + col];
    switch (role)
    {
        case Qt::DisplayRole:
            return value == 0 ? QVariant() : value;

        case Qt::TextAlignmentRole:
            return Qt::AlignCenter;

        default:
            return QVariant();
    }
}

void GridModel::step()
{
    emit dataChanged(index(0, 0), index(8, 8));
    QApplication::processEvents();
}

