#include "GridView.h"
#include "logic/IValidator.h"
#include <QtWidgets/QHeaderView>

#define SECTION_SIZE 30

GridView::GridView(IValidator& validator, QWidget* parent)
    : QTableView(parent)
    , validator_(validator)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    horizontalHeader()->hide();
    verticalHeader()->hide();

    setSelectionMode(QAbstractItemView::SingleSelection);
    setAutoFillBackground(true);
}

void GridView::setModel(QAbstractItemModel* model)
{
    QTableView::setModel(model);
    updateSectionsSize();
}

void GridView::updateSectionsSize()
{
    for (unsigned short i = 0; i < 9; ++i)
    {
        setColumnWidth(i, SECTION_SIZE);
        setRowHeight(i, SECTION_SIZE);
    }
}

QSize GridView::sizeHint() const
{
    return QSize(9 * SECTION_SIZE + 2,
                 9 * SECTION_SIZE + 2);
}

void GridView::paintEvent(QPaintEvent* event)
{
    QPalette pal = palette();
    QColor col = validator_.isValid() ? QColor(200, 255, 200) : QColor(255, 200, 200);
    pal.setColor(QPalette::Base, col);
    setPalette(pal);
    QTableView::paintEvent(event);
}

