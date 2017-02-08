#ifndef UECOMMANDSWIDGET_H
#define UECOMMANDSWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSignalMapper>

#include "../uePOSCommProtocol/ueposcommprotocol.h"

/*!
 * \brief The UeCommandsWidget class
 */
class UeCommandsWidget : public QWidget
{
    Q_OBJECT

private:
    /**
     * @brief m_ueCmdGetDatabasePlacesButton
     */
    QPushButton* m_ueCmdGetDatabasePlacesButton;

protected:
    /**
     * @brief ueSetCmdGetDatabhasePlacesButton
     * @param button
     */
    inline void ueSetCmdGetDatabhasePlacesButton(QPushButton* const button)
        { this->m_ueCmdGetDatabasePlacesButton=button; }

public:
    /**
     * @brief UeCommandsWidget
     * @param parent
     */
    explicit UeCommandsWidget(QWidget *parent = 0);

    /**
     * @brief ueCmdDatabasePlacesButton
     * @return pointer to object representing get database table places data command button
     */
    inline QPushButton* ueCmdDatabasePlacesButton() const
        { return this->m_ueCmdGetDatabasePlacesButton; }

signals:

public slots:
};

#endif // UECOMMANDSWIDGET_H
