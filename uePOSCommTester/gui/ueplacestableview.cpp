#include "ueplacestableview.h"

UePlacesTableView::UePlacesTableView(QWidget* parent)
    : QTableView(parent)
{
    this->setModel(new UeJsonPlacesTableModel(this));
    this->setCornerButtonEnabled(true);
    this->setSortingEnabled(false);
    this->setAlternatingRowColors(true);
    this->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->verticalHeader()->hide();
}   // constructor
