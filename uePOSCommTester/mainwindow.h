#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QHostInfo>
#include <QByteArray>

#include "uecentralwidget.h"
#include "uecommandsdockwidget.h"
#include "gui/ueplacestabledialog.h"

/*!
 * @brief The MainWindow class
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    /**
     * @brief m_ueCentralWidget
     */
    UeCentralWidget* m_ueCentralWidget;

    /**
     * @brief m_ueCommandsDockWidget
     */
    UeCommandsDockWidget* m_ueCommandsDockWidget;

    /**
     * @brief ueInitMenu
     */
    void ueInitMenu();

    /**
     * @brief m_ueCodeRegisterPlacesAction
     */
    QAction* m_ueCodeRegisterPlacesAction;

    /**
     * @brief m_ueCodeListingsMenu
     */
    QMenu* m_ueCodeRegisterMenu;

    /**
     * @brief m_uePlacesViewDialog
     */
    UePlacesTableDialog* m_uePlacesViewDialog;

protected:
    /*!
     * @brief ueSetCentralWidget
     * @param widget
     */
    inline void ueSetCentralWidget(UeCentralWidget* const widget)
        { this->m_ueCentralWidget=widget; }

    /**
     * @brief ueSetCommandsDockWidget
     * @param widget
     */
    inline void ueSetCommandsDockWidget(UeCommandsDockWidget* const widget)
        { this->m_ueCommandsDockWidget=widget; }

    /**
     * @brief ueSetCodeRegisterAction
     * @param action
     */
    inline void ueSetCodeRegisterPlacesAction(QAction* const action)
        { this->m_ueCodeRegisterPlacesAction=action; }

    /**
     * @brief ueSetCodeListingsMenu
     * @param menu
     */
    inline void ueSetCodeRegisterMenu(QMenu* const menu)
        { this->m_ueCodeRegisterMenu=menu; }

    /**
     * @brief ueSetPlacesViewDialog
     * @param dialog
     */
    inline void ueSetPlacesViewDialog(UePlacesTableDialog* const dialog)
        { this->m_uePlacesViewDialog=dialog; }

public:
    /*!
     * @brief MainWindow
     * @param parent
     */
    MainWindow(QWidget *parent = 0);

    /**
     * @brief ueCommandsDockWidget
     * @return pointer to object representing commands dock widget
     */
    inline UeCommandsDockWidget* ueCommandsDockWidget() const
        { return this->m_ueCommandsDockWidget; }

    /**
     * @brief ueCodeRegisterPlacesAction
     * @return pointer to object representing code register places action
     */
    inline QAction* ueCodeRegisterPlacesAction() const
        { return this->m_ueCodeRegisterPlacesAction; }

    /**
     * @brief ueCodeRegisterMenu
     * @return pointer to object representing code register menu
     */
    inline QMenu* ueCodeRegisterMenu() const
        { return this->m_ueCodeRegisterMenu; }

    /**
     * @brief uePlacesViewDialog
     * @return pointer to object representing places view dialog
     */
    inline UePlacesTableDialog* uePlacesViewDialog() const
        { return this->m_uePlacesViewDialog; }

public slots:
    /**
     * @brief ueSlotCmdDatabasePlacesButton
     */
    void ueSlotCmdDatabasePlacesButton();

    /**
     * @brief ueSlotShowPlacesView
     */
    void ueSlotShowPlacesView();

    /**
     * @brief ueSlotUpdatePlacesView
     */
    void ueSlotUpdatePlacesView(const QJsonDocument& newData);
};

#endif // MAINWINDOW_H
