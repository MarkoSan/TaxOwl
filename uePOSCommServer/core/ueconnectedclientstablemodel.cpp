#include "ueconnectedclientstablemodel.h"

UeConnectedClientsTableModel::UeConnectedClientsTableModel(QObject* parent)
    : QAbstractTableModel(parent)
{
}   // constructor

QVariant UeConnectedClientsTableModel::data(const QModelIndex& index,
                                            int role) const
{
    if(!index.isValid()||index.row()>=this->ueConnectedClientData().size()||index.row()<0||index.column()>=UeConnectedClientRecord::NUMBER_OF_FILEDS||index.column()<0)
        return QVariant();

    switch(role)
    {
        case Qt::DisplayRole:
        {
            switch(index.column())
            {
                case UeConnectedClientRecord::INDEX_CLIENT_NAME:
                {
                    return this->ueConnectedClientData().at(index.row())->ueClientName();
                }   // case

                case UeConnectedClientRecord::INDEX_CLIENT_ADDRESS:
                {
                    return this->ueConnectedClientData().at(index.row())->ueClientAddress().toString();
                }   // case

                case UeConnectedClientRecord::INDEX_CLIENT_PORT:
                {
                    return this->ueConnectedClientData().at(index.row())->ueClientPort();
                }   // case

                case UeConnectedClientRecord::INDEX_CLIENT_OS:
                {
                    return this->ueConnectedClientData().at(index.row())->ueClientOS();
                }   // case
            }   // switch
        }   // case
    }   // switch

    return QVariant();
}   // data

QVariant UeConnectedClientsTableModel::headerData(int section,
                                                  Qt::Orientation orientation,
                                                  int role) const
{
    if(role!=Qt::DisplayRole)
        return QVariant();

    switch(orientation)
    {
        case Qt::Horizontal:
        {
            switch(section)
            {
                case UeConnectedClientRecord::INDEX_CLIENT_NAME:
                {
                    return tr("Client name");
                }   // case

                case UeConnectedClientRecord::INDEX_CLIENT_ADDRESS:
                {
                    return tr("Client address");
                }   // case

                case UeConnectedClientRecord::INDEX_CLIENT_PORT:
                {
                    return tr("Client port");
                }   // case

                case UeConnectedClientRecord::INDEX_CLIENT_OS:
                {
                    return tr("Client OS");
                }   // case

                default:
                {
                    return QVariant();
                }   // default
            }   // switch
        }   // case

        case Qt::Vertical:
        {
            return QAbstractTableModel::headerData(section,
                                                   orientation,
                                                   role);
        }   // case
    }   // switch

    return QVariant();
}   // headerData

bool UeConnectedClientsTableModel::insertRows(int row,
                                              int count,
                                              const QModelIndex& parent)
{
    this->beginInsertRows(parent,
                          row,
                          row+count-1);

    for(int index=row; index<row+count; ++index)
    {
        m_ueConnectedClientData.insert(row,
                                       new UeConnectedClientRecord());
    }   // for

    this->endInsertRows();

    return true;
}   // insertRows

/*
bool UeConnectedClientsTableModel::removeRows(int row,
                                              int count,
                                              const QModelIndex& parent)
{
    this->beginRemoveRows(parent,
                          row,
                          row+count);

    for(int index=row; index<row+count; index++)
    {
        m_ueConnectedClientData.removeLast();
    }   // for

    this->endRemoveRows();

    return true;
}   // removeRows
*/

bool UeConnectedClientsTableModel::setData(const QModelIndex& index,
                                           const QVariant& value,
                                           int role)
{
    if(!index.isValid()||index.row()>=this->ueConnectedClientData().size()||index.row()<0||index.column()>=UeConnectedClientRecord::NUMBER_OF_FILEDS||index.column()<0||role!=Qt::EditRole)
    {
        return false;
    }
    else
    {
        int row=index.row();
        int column=index.column();

        switch(column)
        {
            case UeConnectedClientRecord::INDEX_CLIENT_NAME:
            {
                this->ueConnectedClientData().at(row)->ueSetClientName(value.toString());

                break;
            }   // case

            case UeConnectedClientRecord::INDEX_CLIENT_ADDRESS:
            {
                this->ueConnectedClientData().at(row)->ueSetClientAddress(QHostAddress(value.toString()));

                break;
            }   // case

            case UeConnectedClientRecord::INDEX_CLIENT_PORT:
            {
                this->ueConnectedClientData().at(row)->ueSetClientPort(value.toString());

                break;
            }   // case

            case UeConnectedClientRecord::INDEX_CLIENT_OS:
            {
                this->ueConnectedClientData().at(row)->ueSetClientOS(value.toString());

                break;
            }   // case
        }   // switch

        m_ueConnectedClientData.replace(row,
                                        this->ueConnectedClientData().at(row));

        emit(dataChanged(index,
                         index));
    }   // if

    return true;
}   // setData

int UeConnectedClientsTableModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)

    return this->ueConnectedClientData().size();
}   // rowCount

int UeConnectedClientsTableModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)

    return UeConnectedClientRecord::NUMBER_OF_FILEDS;
}   // columnCount

