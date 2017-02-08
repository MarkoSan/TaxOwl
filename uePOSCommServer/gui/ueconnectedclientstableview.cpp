#include "ueconnectedclientstableview.h"

UeConnectedClientsTableView::UeConnectedClientsTableView(QWidget* parent)
    : QTableView(parent)
{
    this->setModel(new UeConnectedClientsTableModel(this));
    this->setAlternatingRowColors(true);
    this->setDragEnabled(false);
    this->setSelectionBehavior(QAbstractItemView::SelectRows);
}   // constructor

void UeConnectedClientsTableView::ueAddConnectedClient(const QString& clientName,
                                                       const QHostAddress& clientAddress,
                                                       const QString& clientPort,
                                                       const QString& clientOS)
{
    UeConnectedClientsTableModel* model=dynamic_cast<UeConnectedClientsTableModel*>(this->model());
    QModelIndex index;

    model->insertRows(0,
                      1,
                      QModelIndex());

    index=model->index(0,
                       UeConnectedClientRecord::INDEX_CLIENT_NAME,
                       QModelIndex());
    model->setData(index,
                   clientName,
                   Qt::EditRole);

    index=model->index(0,
                       UeConnectedClientRecord::INDEX_CLIENT_ADDRESS,
                       QModelIndex());
    model->setData(index,
                   clientAddress.toString(),
                   Qt::EditRole);

    index=model->index(0,
                       UeConnectedClientRecord::INDEX_CLIENT_PORT,
                       QModelIndex());
    model->setData(index,
                   clientPort,
                   Qt::EditRole);

    index=model->index(0,
                       UeConnectedClientRecord::INDEX_CLIENT_OS,
                       QModelIndex());
    model->setData(index,
                   clientOS,
                   Qt::EditRole);
}   // ueAddConnectedClient
