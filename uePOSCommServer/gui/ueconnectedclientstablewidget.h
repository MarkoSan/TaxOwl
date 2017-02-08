#ifndef UECONNECTEDCLIENTSTABLEWIDGET_H
#define UECONNECTEDCLIENTSTABLEWIDGET_H

#include <QObject>
#include <QDockWidget>
#include <QWidget>
#include <QString>
#include <QVBoxLayout>

#include "../gui/ueconnectedclientstableview.h"

class UeConnectedClientsTableWidget : public QDockWidget
{
    Q_OBJECT

private:
    UeConnectedClientsTableView* m_ueConnectedClientsTableView;

protected:
    /*!
     * @brief ueSetConnectedClientsTableView
     * @param view
     */
    inline void ueSetConnectedClientsTableView(UeConnectedClientsTableView* const view)
        { this->m_ueConnectedClientsTableView=view; }

public:
    /*!
     * @brief UeConnectedClientsTableWidget
     * @param title
     * @param parent
     * @param flags
     */
    UeConnectedClientsTableWidget(const QString& title,
                                  QWidget* parent,
                                  Qt::WindowFlags flags);

    /*!
     * @brief ueConnectedClientsTableView
     * @return pointer to object representing connected clients table
     */
    inline UeConnectedClientsTableView* ueConnectedClientsTableView() const
        { return this->m_ueConnectedClientsTableView; }
};

#endif // UECONNECTEDCLIENTSTABLEWIDGET_H
