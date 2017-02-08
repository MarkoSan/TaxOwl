#include "ueconnectedclientstablewidget.h"

UeConnectedClientsTableWidget::UeConnectedClientsTableWidget(const QString& title,
                                                             QWidget* parent,
                                                             Qt::WindowFlags flags)
    : QDockWidget(title,
                  parent,
                  flags)
{
    this->ueSetConnectedClientsTableView(new UeConnectedClientsTableView(this));
    this->setWidget(this->ueConnectedClientsTableView());
}   // constructor
