#ifndef UECONNECTEDCLIENTSTABLEVIEW_H
#define UECONNECTEDCLIENTSTABLEVIEW_H

#include <QWidget>
#include <QTableView>
#include <QHeaderView>
#include <QModelIndex>

#include "../core/ueconnectedclientstablemodel.h"

/*!
 * \brief The UeConnectedClientsTableView class
 */
class UeConnectedClientsTableView : public QTableView
{
    Q_OBJECT

private:
    /*!
     * @brief m_ueConnectedClientsTableModel
     */
    UeConnectedClientsTableModel* m_ueConnectedClientsTableModel;

public:
    /*!
     * @brief UeConnectedClientsTableView
     * @param parent
     */
    UeConnectedClientsTableView(QWidget* parent=Q_NULLPTR);

    /*!
     * @brief ueAddConnectedClient
     * @param clientName
     * @param clientAddress
     * @param clientPort
     */
    void ueAddConnectedClient(const QString& clientName,
                              const QHostAddress& clientAddress,
                              const QString& clientPort,
                              const QString& clientOS);
};

#endif // UECONNECTEDCLIENTSTABLEVIEW_H
