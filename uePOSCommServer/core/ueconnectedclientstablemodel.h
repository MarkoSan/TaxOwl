#ifndef UECONNECTEDCLIENTSTABLEMODEL_H
#define UECONNECTEDCLIENTSTABLEMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include <QList>
#include <QModelIndex>
#include <QVariant>
#include <QHash>
#include <QByteArray>

#include <QDebug>

#include "ueconnectedclientrecord.h"

class UeConnectedClientsTableModel : public QAbstractTableModel
{
    Q_OBJECT

private:
    /*!
     * @brief m_ueConnectedClientData
     */
    QList<UeConnectedClientRecord*> m_ueConnectedClientData;

protected:
    /*!
     * @brief ueSetConnectedClientData
     * @param clientData
     */
    inline void ueSetConnectedClientData(const QList<UeConnectedClientRecord*>& clientData)
        { this->m_ueConnectedClientData=clientData; }

public:
    /*!
     * @brief UeConnectedClientsTableModel
     * @param parent
     */
    UeConnectedClientsTableModel(QObject* parent=Q_NULLPTR);

    /*!
     * @brief ueConnectedClientData
     * @return connected client data
     */
    inline const QList<UeConnectedClientRecord*>& ueConnectedClientData() const
        { return this->m_ueConnectedClientData; }

    /*!
     * @brief rowCount
     * @param parent
     * @return number of rows in model
     */
    int rowCount(const QModelIndex& parent) const;

    /*!
     * @brief columnCount
     * @return number of columns in model
     */
    int columnCount(const QModelIndex& parent) const;

    /*!
     * @brief data
     * @param index
     * @param role
     * @return data for index
     */
    QVariant data(const QModelIndex& index,
                  int role=Qt::DisplayRole) const;

    /*!
     * @brief headerData
     * @param section
     * @param orientation
     * @param role
     * @return header data
     */
    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role=Qt::DisplayRole) const;

    /*!
     * @brief insertRows
     * @param row
     * @param count
     * @param parent
     * @return true if the rows were successfully inserted; otherwise returns false
     */
    bool insertRows(int row,
                    int count,
                    const QModelIndex& parent=QModelIndex());

    /*!
     * @brief removeRows
     * @param row
     * @param count
     * @param parent
     * @return true if the rows were successfully removed; otherwise returns false
     */
/*
    bool removeRows(int row,
                    int count,
                    const QModelIndex& parent=QModelIndex());
*/

    /*!
     * @brief setData
     * @param index
     * @param value
     * @param role
     * @return true if successful; otherwise returns false
     */
    bool setData(const QModelIndex &index,
                 const QVariant &value,
                 int role=Qt::EditRole);
};

#endif // UECONNECTEDCLIENTSTABLEMODEL_H
