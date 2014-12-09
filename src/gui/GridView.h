#ifndef GUI_GRID_VIEW_H
#define GUI_GRID_VIEW_H

#include <QtWidgets/QTableView>

class IValidator;

class GridView : public QTableView
{
    public:
        GridView(IValidator& validator, QWidget* parent = 0);

        void updateSectionsSize();
        virtual void setModel(QAbstractItemModel* model);
        virtual QSize sizeHint() const;

    protected:
        virtual void paintEvent(QPaintEvent* event);

    private:
        IValidator& validator_;
};

#endif

