#include "ueplacestabledialog.h"

UePlacesTableDialog::UePlacesTableDialog(QWidget* parent,
                                         Qt::WindowFlags f)
    : QDialog(parent)
{
    Q_UNUSED(f)

    this->setLayout(new QVBoxLayout);

    this->ueSetPlacesTableView(new UePlacesTableView(this));

    this->layout()->addWidget(this->uePlacesTableView());
}   // contructor
