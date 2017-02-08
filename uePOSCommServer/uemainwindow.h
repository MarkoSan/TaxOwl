#ifndef UEMAINWINDOW_H
#define UEMAINWINDOW_H

#include <QMainWindow>
#include <QNetworkConfigurationManager>
#include <QUdpSocket>
#include <QTimer>
#include <QTcpSocket>
#include <QByteArray>
#include <QList>
#include <QDebug>
#include <QApplication>
#include <QSqlDatabase>
#include <QHostInfo>
#include <QSysInfo>

#include "gui/uedatabaseserversettingswindow.h"
#include "gui/uecentralwidget.h"
#include "gui/ueconnectedclientstablewidget.h"

#include "../ueSyntaxHiglighter/uelogwindow.h"

#include "net/uetcpserver.h"
#include "net/uetask.h"

#include "../uePOSCommProtocol/ueposcommprotocol.h"
#include "../uePOSCommProtocol/uedefaults.h"

#include "core/ueconnectedclientrecord.h"

#include "settings/uesettings.h"

#include "database/models/ueplacesmodel.h"

/*!
 * @brief The UeMainWindow class
 */
class UeMainWindow : public QMainWindow
{
    Q_OBJECT

private:
    /*!
     * @brief m_ueNetworkConfigurationManager
     */
    QNetworkConfigurationManager* m_ueNetworkConfigurationManager;

    /*!
     * @brief m_ueTcpServer
     */
    UeTcpServer* m_ueTcpServer;

    /*!
     * @brief m_ueNetworkInformationSocket
     */
    QUdpSocket* m_ueNetworkInformationSocket;

    /*!
     * @brief m_ueNetworkInformationBroadcastTimer
     */
    QTimer* m_ueNetworkInformationBroadcastTimer;

    /*!
     * @brief m_ueTcpClientSocket
     */
    QTcpSocket* m_ueTcpClientSocket;

    /*!
     * @brief m_ueConnectedClientsTableWidget
     */
    UeConnectedClientsTableWidget* m_ueConnectedClientsTableWidget;

    /*!
     * @brief m_ueSettings
     */
    UeSettings* m_ueSettings;

    /*!
     * @brief m_ueDatabaseSettingsWindow
     */
    UeDatabaseServerSettingsWindow* m_ueDatabaseServerSettingsWindow;

    /*!
     * @brief m_uePlacesModel
     */
    UePlacesModel* m_uePlacesModel;

    /*!
     * @brief m_ueDatabase
     */
    QSqlDatabase m_ueDatabase;

protected:
    /*!
     * @brief ueSetNetworkConfigurationManager
     * @param manager
     */
    inline void ueSetNetworkConfigurationManager(QNetworkConfigurationManager* const manager)
        { this->m_ueNetworkConfigurationManager=manager; }

    /*!
     * @brief ueSetTcpServer
     * @param server
     */
    inline void ueSetTcpServer(UeTcpServer* const server)
        { this->m_ueTcpServer=server; }

    /*!
     * @brief ueSetUdpSocket
     * @param socket
     */
    inline void ueSetNetworkInformationSocket(QUdpSocket* const socket)
        { this->m_ueNetworkInformationSocket=socket; }

    /*!
     * @brief ueSetNetworkInformationBroadcastTimer
     * @param timer
     */
    inline void ueSetNetworkInformationBroadcastTimer(QTimer* const timer)
        { this->m_ueNetworkInformationBroadcastTimer=timer; }

    /*!
     * @brief ueSetTcpClientSocket
     * @param socket
     */
    inline void ueSetTcpClientSocket(QTcpSocket* const socket)
        { this->m_ueTcpClientSocket=socket; }

    /*!
     * @brief ueSetConnectedClientsTableWidget
     * @param widget
     */
    inline void ueSetConnectedClientsTableWidget(UeConnectedClientsTableWidget* widget)
        { this->m_ueConnectedClientsTableWidget=widget; }

    /*!
     * @brief ueSetSettings
     * @param settings
     */
    inline void ueSetSettings(UeSettings* const settings)
        { this->m_ueSettings=settings; }

    /*!
     * @brief ueSetDatabaseServerSettingsWindow
     * @param window
     */
    inline void ueSetDatabaseServerSettingsWindow(UeDatabaseServerSettingsWindow* const window)
        { this->m_ueDatabaseServerSettingsWindow=window; }

    /*!
     * @brief ueSetPlacesModel
     * @param model
     */
    inline void ueSetPlacesModel(UePlacesModel* const model)
        { this->m_uePlacesModel=model; }

    /*!
     * @brief ueSetDatabase
     * @param database
     */
    inline void ueSetDatabase(const QSqlDatabase& database)
        { this->m_ueDatabase=database; }

public:
    /*!
     * @brief UeMainWindow
     * @param parent
     */
    UeMainWindow(QWidget *parent = 0);

    /*!
     * @brief ~UeMainWindow
     */
    ~UeMainWindow();

    /*!
     * @brief ueNetworkConfigurationManager
     * @return pointer to object representing network configuration manager
     */
    inline QNetworkConfigurationManager* ueNetworkConfigurationManager() const
        { return this->m_ueNetworkConfigurationManager; }

    /*!
     * @brief ueTcpServer
     * @return pointer to object representing TCP server
     */
    inline UeTcpServer* ueTcpServer() const
        { return this->m_ueTcpServer; }

    /*!
     * @brief ueNetworkInformationSocket
     * @return pointer to object representing network information socket
     */
    inline QUdpSocket* ueNetworkInformationSocket() const
        { return this->m_ueNetworkInformationSocket; }

    /*!
     * @brief ueNetworkInformationBroadcastTimer
     * @return pointer to object represnting network information broadcast timer
     */
    inline QTimer* ueNetworkInformationBroadcastTimer() const
        { return this->m_ueNetworkInformationBroadcastTimer; }

    /*!
     * @brief ueTcpClientSocket
     * @return pointer to object representing tcp client socket
     */
    inline QTcpSocket* ueTcpClientSocket() const
        { return this->m_ueTcpClientSocket; }

    /*!
     * @brief ueConnectedClientsTableWidget
     * @return pointer to object representing connected clients table widget
     */
    inline UeConnectedClientsTableWidget* ueConnectedClientsTableWidget() const
        { return this->m_ueConnectedClientsTableWidget; }

    /*!
     * @brief ueSettings
     * @return pointer to object representing database settings
     */
    inline UeSettings* ueSettings() const
        { return this->m_ueSettings; }

    /*!
     * @brief ueDatabaseServerSettingsWindow
     * @return pointer to object representing database server settings window
     */
    inline UeDatabaseServerSettingsWindow* ueDatabaseServerSettingsWindow() const
        { return this->m_ueDatabaseServerSettingsWindow; }

    /*!
     * @brief uePlacesModel
     * @return pointer to object representing places model
     */
    inline UePlacesModel* uePlacesModel() const
        { return this->m_uePlacesModel; }

    /*!
     * @brief ueDatabase
     * @return database object
     */
    inline QSqlDatabase/*&*/ ueDatabase()
        { return this->m_ueDatabase; }

public slots:
    /*!
     * @brief ueSlotNetworkConfigurationAdded
     * @param config
     */
    void ueSlotNetworkConfigurationAdded(const QNetworkConfiguration& config);

    /*!
     * @brief ueSlotNetworkConfigurationChanged
     * @param config
     */
    void ueSlotNetworkConfigurationChanged(const QNetworkConfiguration& config);

    /*!
     * @brief ueSlotNetworkConfigurationRemoved
     * @param config
     */
    void ueSlotNetworkConfigurationRemoved(const QNetworkConfiguration& config);

    /*!
     * @brief ueSlotNetworkOnlineStateChanged
     * @param isOnline
     */
    void ueSlotNetworkOnlineStateChanged(bool isOnline);

    /*!
     * @brief ueSlotNetworkUpdateCompleted
     */
    void ueSlotNetworkUpdateCompleted();

    /*!
     * @brief ueSlotTcpServerAcceptError
     * @param socketError
     */
    void ueSlotTcpServerAcceptError(QAbstractSocket::SocketError socketError);

    /*!
     * @brief ueSlotTcpServerNewConnection
     */
    void ueSlotTcpServerNewConnection();

    /*!
     * @brief ueSlotNetworkInformationSocketConnected
     */
    void ueSlotNetworkInformationSocketConnected();

    /*!
     * @brief ueSlotNetworkInformationSocketDisconnected
     */
    void ueSlotNetworkInformationSocketDisconnected();

    /*!
     * @brief ueSlotNetworkInformationSocketError
     * @param socketError
     */
    void ueSlotNetworkInformationSocketError(QAbstractSocket::SocketError socketError);

    /*!
     * @brief ueSlotNetworkInformationSocketHostFound
     */
    void ueSlotNetworkInformationSocketHostFound();

    /*!
     * @brief ueSlotNetworkInformationSocketStateChanged
     * @param socketState
     */
    void ueSlotNetworkInformationSocketStateChanged(QAbstractSocket::SocketState socketState);

    /*!
     * \brief ueSlotBroadcastNetworkInfo
     * \param checked
     */
    void ueSlotBroadcastNetworkInfo(bool checked=false);

    /*!
     * @brief ueSlotAddEventInfoLog
     * @param messageType
     * @param message
     */
    void ueSlotAddEventInfoLog(const UeLogEntryType& messageType,
                               const QString& message);

    /*!
     * @brief ueSlotReadSocketData
     */
    void ueSlotReadSocketData();

    /*!
     * @brief ueSlotCentralWidgetClearLogWindow
     * @param checked
     */
    void ueSlotCentralWidgetClearLogWindow(bool checked=false);

    /*!
     * @brief ueSlotQuitApp
     * @param checked
     */
    void ueSlotQuitApp(bool checked=false);

    /*!
     * @brief ueSlotTestDatabaseConnection
     * @param checked
     * @return true if succesfull, otherwise false
     */
    bool ueSlotTestDatabaseConnection(bool checked=false);

    /*!
     * @brief ueSlotSaveCompleted
     * @param status
     */
    void ueSlotSaveCompleted(QSettings::Status status);

    /*!
     * @brief ueSlotConnectToDatabase
     * @param database
     * @param databaseServerAddress
     * @param databaseServerPort
     * @param databaseName
     * @param databaseUsername
     * @param databasePassword
     * @return true if succesfull, otherwise false
     */
    bool ueSlotConnectToDatabase(const QString& databaseServerAddress,
                                 const QString& databaseServerPort,
                                 const QString& databaseName,
                                 const QString& databaseUsername,
                                 const QString& databasePassword);

    /*!
     * \brief ueSlotDataArrived
     * \param executedCommand
     * \param fetchedData
     * \param parameters
     */
    void ueSlotDataArrived(const UePosCommProtocolArch::UeCommand& executedCommand,
                           const QByteArray& fetchedData,
                           const QList<QVariant>& parameters);
};

#endif // UEMAINWINDOW_H
