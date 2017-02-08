#include "uemainwindow.h"

UeMainWindow::UeMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setCentralWidget(new UeCentralWidget(this));

    connect(dynamic_cast<UeCentralWidget*>(this->centralWidget())->ueButtonClear(),
            SIGNAL(clicked(bool)),
            this,
            SLOT(ueSlotCentralWidgetClearLogWindow(bool)));

    connect(dynamic_cast<UeCentralWidget*>(this->centralWidget())->ueCmdSendNetworkSettingsButton(),
            SIGNAL(clicked(bool)),
            this,
            SLOT(ueSlotBroadcastNetworkInfo(bool)));

    connect(dynamic_cast<UeCentralWidget*>(this->centralWidget())->ueButtonQuit(),
            SIGNAL(clicked(bool)),
            this,
            SLOT(ueSlotQuitApp(bool)));

    this->ueSetConnectedClientsTableWidget(new UeConnectedClientsTableWidget(tr("Connected Clients"),
                                                                             this,
                                                                             Qt::WindowFlags()));

    this->addDockWidget(Qt::RightDockWidgetArea,
                        this->ueConnectedClientsTableWidget());

    this->ueSetSettings(new UeSettings(this,
                                       QApplication::applicationDirPath()+
                                       "/"+
                                       UeSettingsDefaults::UeSettings::SETTINGS_FILE_NAME));

    connect(this->ueSettings(),
            SIGNAL(ueSignalSaveCompleted(QSettings::Status)),
            this,
            SLOT(ueSlotSaveCompleted(QSettings::Status)));

    this->ueSetDatabaseServerSettingsWindow(new UeDatabaseServerSettingsWindow(this));

    connect(this->ueDatabaseServerSettingsWindow()->ueSaveSettingsButton(),
            SIGNAL(clicked(bool)),
            this->ueSettings(),
            SLOT(ueSlotSaveSettings(bool)));

    connect(this->ueDatabaseServerSettingsWindow()->ueTestParametersButton(),
            SIGNAL(clicked(bool)),
            this,
            SLOT(ueSlotTestDatabaseConnection(bool)));

    connect(this->ueDatabaseServerSettingsWindow()->ueDatabaserServerAddressEditor(),
            SIGNAL(textChanged(QString)),
            this->ueSettings(),
            SLOT(ueSetDatabaseServerAddress(QString)));

    connect(this->ueDatabaseServerSettingsWindow()->ueDatabaseServerPortEditor(),
            SIGNAL(textChanged(QString)),
            this->ueSettings(),
            SLOT(ueSetDatabaseServerPort(QString)));

    connect(this->ueDatabaseServerSettingsWindow()->ueDatabaseNameEditor(),
            SIGNAL(textChanged(QString)),
            this->ueSettings(),
            SLOT(ueSetDatabaseName(QString)));

    connect(this->ueDatabaseServerSettingsWindow()->ueDatabaseUserNameEditor(),
            SIGNAL(textChanged(QString)),
            this->ueSettings(),
            SLOT(ueSetDatabaseUsername(QString)));

    connect(this->ueDatabaseServerSettingsWindow()->ueDatabasePasswordEditor(),
            SIGNAL(textChanged(QString)),
            this->ueSettings(),
            SLOT(ueSetDatabasePassword(QString)));

    this->ueSetDatabase(QSqlDatabase::addDatabase(UeSettingsDefaults::UeDatabase::DATABASE_DRIVER));

    if(!this->ueSettings()->ueSlotLoadSettings())
    {
        this->ueDatabaseServerSettingsWindow()->show();
    }
    else
    {
        this->ueDatabaseServerSettingsWindow()->ueDatabaserServerAddressEditor()->setText(this->ueSettings()->ueDatabaseServerAddress());
        this->ueDatabaseServerSettingsWindow()->ueDatabaseServerPortEditor()->setText(this->ueSettings()->ueDatabaseServerPort());
        this->ueDatabaseServerSettingsWindow()->ueDatabaseNameEditor()->setText(this->ueSettings()->ueDatabaseName());
        this->ueDatabaseServerSettingsWindow()->ueDatabaseUserNameEditor()->setText(this->ueSettings()->ueDatabaseUsername());
        this->ueDatabaseServerSettingsWindow()->ueDatabasePasswordEditor()->setText(this->ueSettings()->ueDatabasePassword());

        if(this->ueSlotTestDatabaseConnection())
        {
        }   // if

        this->ueSetPlacesModel(new UePlacesModel(this,
                                                 this->ueDatabase()));
    }   // if

    this->ueSetNetworkConfigurationManager(new QNetworkConfigurationManager(this));

    connect(this->ueNetworkConfigurationManager(),
            SIGNAL(configurationRemoved(QNetworkConfiguration)),
            this,
            SLOT(ueSlotNetworkConfigurationRemoved(QNetworkConfiguration)));
    connect(this->ueNetworkConfigurationManager(),
            SIGNAL(configurationChanged(QNetworkConfiguration)),
            this,
            SLOT(ueSlotNetworkConfigurationChanged(QNetworkConfiguration)));
    connect(this->ueNetworkConfigurationManager(),
            SIGNAL(configurationAdded(QNetworkConfiguration)),
            this,
            SLOT(ueSlotNetworkConfigurationAdded(QNetworkConfiguration)));
    connect(this->ueNetworkConfigurationManager(),
            SIGNAL(onlineStateChanged(bool)),
            this,
            SLOT(ueSlotNetworkOnlineStateChanged(bool)));
    connect(this->ueNetworkConfigurationManager(),
            SIGNAL(updateCompleted()),
            this,
            SLOT(ueSlotNetworkUpdateCompleted()));

    this->ueSetTcpServer(new UeTcpServer(this,
                                         this->ueSettings()));

    connect(this->ueTcpServer(),
            SIGNAL(acceptError(QAbstractSocket::SocketError)),
            this,
            SLOT(ueSlotTcpServerAcceptError(QAbstractSocket::SocketError)));

    connect(this->ueTcpServer(),
            SIGNAL(newConnection()),
            this,
            SLOT(ueSlotTcpServerNewConnection()));

    connect(this->ueTcpServer(),
            SIGNAL(ueSignalEmitLogEvent(UeLogEntryType,
                                        QString)),
            this,
            SLOT(ueSlotAddEventInfoLog(UeLogEntryType,
                                       QString)));

    connect(this->ueTcpServer(),
            SIGNAL(ueSignalDataArrived(const UePosCommProtocolArch::UeCommand&,
                                       const QByteArray&,
                                       const QList<QVariant>&)),
            this,
            SLOT(ueSlotDataArrived(const UePosCommProtocolArch::UeCommand&,
                                   const QByteArray&,
                                   const QList<QVariant>&)));

    this->ueTcpServer()->ueStart(UeDefaults::TCP_SERVER_DEFAULT_PORT);

    this->ueSetNetworkInformationSocket(new QUdpSocket(this));

    connect(this->ueNetworkInformationSocket(),
            SIGNAL(connected()),
            this,
            SLOT(ueSlotNetworkInformationSocketConnected()));

    connect(this->ueNetworkInformationSocket(),
            SIGNAL(disconnected()),
            this,
            SLOT(ueSlotNetworkInformationSocketDisconnected()));

    connect(this->ueNetworkInformationSocket(),
            SIGNAL(error(QAbstractSocket::SocketError)),
            this,
            SLOT(ueSlotNetworkInformationSocketError(QAbstractSocket::SocketError)));

    connect(this->ueNetworkInformationSocket(),
            SIGNAL(hostFound()),
            this,
            SLOT(ueSlotNetworkInformationSocketHostFound()));

    connect(this->ueNetworkInformationSocket(),
            SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this,
            SLOT(ueSlotNetworkInformationSocketStateChanged(QAbstractSocket::SocketState)));

//    this->ueSetNetworkInformationBroadcastTimer(new QTimer(this));

//    connect(this->ueNetworkInformationBroadcastTimer(),
//            SIGNAL(timeout()),
//            this,
//            SLOT(ueSlotNetworkInformationBroadcastTimerTimeout()));

//    this->ueNetworkInformationBroadcastTimer()->start(20000);

    this->ueSlotBroadcastNetworkInfo();
}   // constructor

UeMainWindow::~UeMainWindow()
{
    delete this->ueNetworkConfigurationManager();
}   // destructor

void UeMainWindow::ueSlotNetworkConfigurationAdded(const QNetworkConfiguration& config)
{
    this->ueSlotAddEventInfoLog(UeLogEntryType::INFO,
                                tr("Network configuarion added").append(" ")
                                                                .append(config.name())
                                                                .append(" ")
                                                                .append(QString::number(config.type(),
                                                                                        2)));

//    if(!this->ueNetworkConfigurationManager()->isOnline())
//    {
//        this->ueTcpServer()->ueRestart(QHostAddress::LocalHost,
//                                       UeDefaults::TCP_SERVER_DEFAULT_PORT);
//    }   // if
}   // ueSlotNetworkConfigurationAdded

void UeMainWindow::ueSlotNetworkConfigurationChanged(const QNetworkConfiguration& config)
{
    this->ueSlotAddEventInfoLog(UeLogEntryType::INFO,
                                tr("Network configuarion changed").append(" ")
                                                                  .append(config.name())
                                                                  .append(" ")
                                                                  .append(QString::number(config.state())));
//    if(!this->ueNetworkConfigurationManager()->isOnline())
//    {
//        this->ueTcpServer()->ueRestart(QHostAddress::LocalHost,
//                                       UeDefaults::TCP_SERVER_DEFAULT_PORT);
//    }   // if
}   // ueSlotNetworkConfigurationChanged

void UeMainWindow::ueSlotNetworkConfigurationRemoved(const QNetworkConfiguration& config)
{
    this->ueSlotAddEventInfoLog(UeLogEntryType::INFO,
                                tr("Network configuarion removed").append(" ")
                                                                  .append(config.name()));

//    if(!this->ueNetworkConfigurationManager()->isOnline())
//    {
//        this->ueTcpServer()->ueRestart(QHostAddress::LocalHost,
//                                       UeDefaults::TCP_SERVER_DEFAULT_PORT);
//    }   // if
}   // ueSlotNetworkConfigurationRemoved

void UeMainWindow::ueSlotNetworkOnlineStateChanged(bool isOnline)
{
    this->ueSlotAddEventInfoLog(isOnline?UeLogEntryType::INFO:UeLogEntryType::ERROR,
                                tr("Network online state changed").append(" ")
                                                                  .append(isOnline?tr(" ONLINE "):tr(" OFFLINE ")));
    if(!isOnline)
    {
        this->ueTcpServer()->ueRestart(QHostAddress::LocalHost,
                                       UeDefaults::TCP_SERVER_DEFAULT_PORT);
    }   // if
}   // ueSlotNetworkOnlineStateChanged

void UeMainWindow::ueSlotNetworkUpdateCompleted()
{
//    this->ueSlotAddEventInfoLog(UeLogEntryType::INFO,
//                                tr("Network discovery completed"));

//    if(!this->ueNetworkConfigurationManager()->isOnline())
//    {
//        this->ueTcpServer()->ueRestart(QHostAddress::LocalHost,
//                                       UeDefaults::TCP_SERVER_DEFAULT_PORT);
//    }   // if
}   // ueSlotNetworkUpdateCompleted

void UeMainWindow::ueSlotTcpServerAcceptError(QAbstractSocket::SocketError socketError)
{
    this->ueSlotAddEventInfoLog(UeLogEntryType::ERROR,
                                tr("Could not accept new connection because of socket error ").append(socketError));
}   // ueSlotTcpServerAcceptError

void UeMainWindow::ueSlotTcpServerNewConnection()
{
    if(this->ueTcpServer()->hasPendingConnections())
    {
        this->ueSetTcpClientSocket(this->ueTcpServer()->nextPendingConnection());

        this->ueSlotAddEventInfoLog(UeLogEntryType::INFO,
                                    tr("New incoming connection from host")
                                    .append(" ")
                                    .append(tr("with IP address"))
                                    .append(" ")
                                    .append(this->ueTcpClientSocket()->peerAddress().toString())    //RESOLVED strange IP address returned - support only IPv4 address
                                    .append(" ")
                                    .append(tr("using port"))
                                    .append(" ")
                                    .append(QString::number(this->ueTcpClientSocket()->peerPort())));

        connect(this->ueTcpClientSocket(),
                SIGNAL(readyRead()),
                this,
                SLOT(ueSlotReadSocketData()));
    }   // if
}   // ueSlotTcpServerNewConnection

void UeMainWindow::ueSlotNetworkInformationSocketConnected()
{
    this->ueSlotAddEventInfoLog(UeLogEntryType::INFO,
                                tr("Connection to network information socket has been succesfully established"));
}   // ueSlotNetworkInformationSocketConnected

void UeMainWindow::ueSlotNetworkInformationSocketDisconnected()
{
    this->ueSlotAddEventInfoLog(UeLogEntryType::INFO,
                                tr("Connection to network information socket has been disconnected"));
}   // ueSlotNetworkInformationSocketDisconnected

void UeMainWindow::ueSlotNetworkInformationSocketError(QAbstractSocket::SocketError socketError)
{
    this->ueSlotAddEventInfoLog(UeLogEntryType::ERROR,
                                tr("Network information socket error").append(" ")
                                                                      .append(QString::number(socketError))
                                                                      .append(" ")
                                                                      .append("(")
                                                                      .append(this->ueNetworkInformationSocket()->errorString())
                                                                      .append(")")
                                                                      .append(" ")
                                                                      .append(tr("occured")));
}   // ueSlotNetworkInformationSocketError

void UeMainWindow::ueSlotNetworkInformationSocketHostFound()
{
    this->ueSlotAddEventInfoLog(UeLogEntryType::WARNING,
                                tr("Network information socket host found"));
}   // ueSlotNetworkInformationSocketHostFound

void UeMainWindow::ueSlotNetworkInformationSocketStateChanged(QAbstractSocket::SocketState socketState)
{
    this->ueSlotAddEventInfoLog(UeLogEntryType::WARNING,
                                tr("Network information socket state changed to").append(" ")
                                                                                 .append(QString::number(socketState)));
}   // ueSlotNetworkInformationSocketStateChanged

void UeMainWindow::ueSlotBroadcastNetworkInfo(bool checked)
{
    Q_UNUSED(checked)

    QList<QVariant> parameters;
    QByteArray datagram;
    quint32 dataSize;

    parameters.append(this->ueTcpServer()->ueServerIPv4().toString());
    parameters.append(QString::number(this->ueTcpServer()->ueServerPort()));

    datagram=UePOSCommProtocol::ueEncodeCommand(UePosCommProtocolArch::UeCommand::CMD_GET_NETWORK_SETTINGS,
                                                parameters,
                                                dataSize);

    if(this->ueNetworkInformationSocket()->writeDatagram(datagram.data(),
                                                         datagram.size(),
                                                         QHostAddress::Broadcast,
                                                         UeDefaults::UDP_NETWORK_INFORMATION_SOCKET_PORT)>0)
    {
        this->ueSlotAddEventInfoLog(UeLogEntryType::INFO,
                                    tr("Network information data")
                                    .append(" ")
                                    .append(" ")
                                    .append(tr("sent via broadcast")));
    }
    else
    {
        this->ueSlotAddEventInfoLog(UeLogEntryType::ERROR,
                                    tr("Error sending Network information data")
                                    .append(" ")
                                    .append(datagram.toHex())
                                    .append(" ")
                                    .append(tr("via broadcast"))
                                    .append(" ")
                                    .append(tr("with error"))
                                    .append(" ")
                                    .append(QString::number(this->ueNetworkInformationSocket()->error()))
                                    .append(" ")
                                    .append("(")
                                    .append(this->ueNetworkInformationSocket()->errorString())
                                    .append(")"));
    }   // if
}   // ueSlotBroadcastNetworkInfo

void UeMainWindow::ueSlotAddEventInfoLog(const UeLogEntryType& messageType,
                                         const QString& message)
{
        dynamic_cast<UeCentralWidget*>(this->centralWidget())->ueLogWindow()->appendPlainText(UeLogWindow::ueCreateLogEntry(messageType,
                                                                                                                            message));
}   // ueSlotAddEventInfoLog

void UeMainWindow::ueSlotReadSocketData()
{
    QList<QVariant> incomingData;
    QByteArray incomingMessage=this->ueTcpClientSocket()->readAll();
    UePosCommProtocolArch::UeCommand command=UePOSCommProtocol::ueDecodeCommand(incomingMessage,
                                                                                incomingData);

    switch(command)
    {
        case UePosCommProtocolArch::UeCommand::CMD_GET_NETWORK_SETTINGS:
        {
            break;
        }   // case

        case UePosCommProtocolArch::UeCommand::CMD_INVALID_COMMAND:
        {
            break;
        }   // case

        case UePosCommProtocolArch::UeCommand::ACK_CMD_GET_NETWORK_SETTINGS:
        {
            QString clientHostname=incomingData[2].toString();
            QString clientAddress=incomingData[0].toString();
            QString clientPort=QString::number(incomingData[1].toInt());
            QString clientOS=incomingData[3].toString();

            this->ueSlotAddEventInfoLog(UeLogEntryType::INFO,
                                        tr("Acknowledge").append(" ")
                                                         .append(UePOSCommProtocol::ueCommandToString(command))
                                                         .append(" ")
                                                         .append(tr("from"))
                                                         .append(" ")
                                                         .append(clientHostname)
                                                         .append(" ")
                                                         .append(tr("with IP address"))
                                                         .append(" ")
                                                         .append(clientAddress)
                                                         .append(" ")
                                                         .append(tr("using port"))
                                                         .append(" ")
                                                         .append(clientPort));

            dynamic_cast<UeConnectedClientsTableWidget*>(this->ueConnectedClientsTableWidget())->ueConnectedClientsTableView()->ueAddConnectedClient(clientHostname,
                                                                                                                                                     QHostAddress(clientAddress),
                                                                                                                                                     clientPort,
                                                                                                                                                     clientOS);

            break;
        }   // case

        case UePosCommProtocolArch::UeCommand::CMD_DATABASE_GET_PLACES:
        {
            quint32 dataSize;

            this->ueSlotAddEventInfoLog(UeLogEntryType::INFO,
                                        tr("Incoming command").append(" ")
                                                              .append(UePOSCommProtocol::ueCommandToString(command)));

            QString sqlStatusMessage=QString();
            QByteArray placesData=this->uePlacesModel()->ueFetchData(sqlStatusMessage);
            QList<QVariant> commandParamater=QList<QVariant>();

            commandParamater.append(placesData);

            QByteArray message=UePOSCommProtocol::ueEncodeCommand(UePosCommProtocolArch::UeCommand::ACK_CMD_DATABASE_GET_PLACES,
                                                                  commandParamater,
                                                                  dataSize);

            if(this->ueTcpClientSocket()->write(message,
                                                message.size())>0)
            {
                this->ueSlotAddEventInfoLog(UeLogEntryType::INFO,
                                            tr("Sending acknowledge").append(" ")
                                                                     .append(UePOSCommProtocol::ueCommandToString(UePosCommProtocolArch::UeCommand::ACK_CMD_DATABASE_GET_PLACES))
                                                                     .append(" ")
                                                                     .append(tr("to"))
                                                                     .append(this->ueTcpClientSocket()->peerName())
                                                                     .append(" ")
                                                                     .append("(")
                                                                     .append(this->ueTcpClientSocket()->peerAddress().toString())
                                                                     .append(" ")
                                                                     .append("on port")
                                                                     .append(" ")
                                                                     .append(QString::number(this->ueTcpClientSocket()->peerPort()))
                                                                     .append(")"));
            }
            else
            {
                this->ueSlotAddEventInfoLog(UeLogEntryType::ERROR,
                                            tr("Error").append(" ")
                                                       .append(this->ueTcpClientSocket()->errorString()
                                                       .append(" ")
                                                       .append(tr("sending acknowledge"))
                                                       .append(" ")
                                                       .append(UePOSCommProtocol::ueCommandToString(UePosCommProtocolArch::UeCommand::ACK_CMD_DATABASE_GET_PLACES))
                                                       .append(" ")
                                                       .append(tr("to"))
                                                       .append(this->ueTcpClientSocket()->peerName())
                                                       .append(" ")
                                                       .append("(")
                                                       .append(this->ueTcpClientSocket()->peerAddress().toString())
                                                       .append(" ")
                                                       .append("on port")
                                                       .append(" ")
                                                       .append(QString::number(this->ueTcpClientSocket()->peerPort()))
                                                       .append(")")));
            }   // if

            break;
        }   // case

        case UePosCommProtocolArch::UeCommand::ACK_CMD_DATABASE_GET_PLACES:
        {
            break;
        }   // case
    }   // switch
}   // ueSlotReadSocketData

void UeMainWindow::ueSlotCentralWidgetClearLogWindow(bool checked)
{
    Q_UNUSED(checked)

    dynamic_cast<UeCentralWidget*>(this->centralWidget())->ueLogWindow()->clear();
}   // ueSlotCentralWidgetClearLogWindow

void UeMainWindow::ueSlotQuitApp(bool checked)
{
    Q_UNUSED(checked)

    qApp->quit();
}   // ueSlotQuitApp

bool UeMainWindow::ueSlotTestDatabaseConnection(bool checked)
{
    Q_UNUSED(checked)

    bool result=false;

    if(this->ueSlotConnectToDatabase(this->ueSettings()->ueDatabaseServerAddress(),
                                     this->ueSettings()->ueDatabaseServerPort(),
                                     this->ueSettings()->ueDatabaseName(),
                                     this->ueSettings()->ueDatabaseUsername(),
                                     this->ueSettings()->ueDatabasePassword()))
    {
        this->ueDatabase().close();

        result=true;
    }   // if

    return result;
}   // ueSlotTestParametersButtonPressed

void UeMainWindow::ueSlotSaveCompleted(QSettings::Status status)
{
    switch(status)
    {
        case QSettings::NoError:
        {
            this->ueSlotAddEventInfoLog(UeLogEntryType::INFO,
                                        tr("Settings saved to").append(" ")
                                                               .append(this->ueSettings()->ueSettingsFile())
                                                               .append(" ")
                                                               .append(tr("successfully.")));

            break;
        }   // case

        case QSettings::AccessError:
        {
            this->ueSlotAddEventInfoLog(UeLogEntryType::INFO,
                                        tr("Settings save error").append(" ")
                                                                 .append(status)
                                                                 .append(" ")
                                                                 .append(tr("to"))
                                                                 .append(" ")
                                                                 .append(this->ueSettings()->ueSettingsFile()));

            break;
        }   // case

        case QSettings::FormatError:
        {
            this->ueSlotAddEventInfoLog(UeLogEntryType::INFO,
                                        tr("Settings save error").append(" ")
                                                                 .append(status)
                                                                 .append(" ")
                                                                 .append(tr("to"))
                                                                 .append(" ")
                                                                 .append(this->ueSettings()->ueSettingsFile()));

            break;
        }   // case
    }   // switch
}   // ueSlotSaveCompleted

bool UeMainWindow::ueSlotConnectToDatabase(const QString& databaseServerAddress,
                                           const QString& databaseServerPort,
                                           const QString& databaseName,
                                           const QString& databaseUsername,
                                           const QString& databasePassword)
{
    bool result=false;

    if(!QSqlDatabase::connectionNames().contains(UeSettingsDefaults::UeDatabase::DATABASE_CONNECTION_NAME,
                                                 Qt::CaseInsensitive))
    {
        this->ueSetDatabase(QSqlDatabase::addDatabase(UeSettingsDefaults::UeDatabase::DATABASE_DRIVER,
                                                      UeSettingsDefaults::UeDatabase::DATABASE_CONNECTION_NAME));
    }   // if

    this->ueDatabase().setHostName(databaseServerAddress);
    this->ueDatabase().setPort(databaseServerPort.toInt());
    this->ueDatabase().setDatabaseName(databaseName);
    this->ueDatabase().setUserName(databaseUsername);
    this->ueDatabase().setPassword(databasePassword);

    if(!this->ueDatabase().open())
    {
        if(this->ueDatabase().lastError().isValid())
        {
            this->ueSlotAddEventInfoLog(UeLogEntryType::INFO,
                                        tr("Error connecting to database").append(" ")
                                                                          .append(this->ueDatabase().lastError().text()));
        }
        else
        {
            this->ueSlotAddEventInfoLog(UeLogEntryType::INFO,
                                        tr("Unknown error connecting to database"));
        }   // if
    }
    else
    {
        this->ueSlotAddEventInfoLog(UeLogEntryType::INFO,
                                    tr("Database connection successful, connection parameters are ok"));

        result=true;
    }   // if

    return result;
}   // ueSlotConnectToDatabase

void UeMainWindow::ueSlotDataArrived(const UePosCommProtocolArch::UeCommand& executedCommand,
                                     const QByteArray& fetchedData,
                                     const QList<QVariant>& parameters)
{
    switch(executedCommand)
    {
        case UePosCommProtocolArch::UeCommand::CMD_GET_NETWORK_SETTINGS:
        {
            break;
        }   // case

        case UePosCommProtocolArch::UeCommand::CMD_INVALID_COMMAND:
        {
            break;
        }   // case

        case UePosCommProtocolArch::UeCommand::ACK_CMD_GET_NETWORK_SETTINGS:
        {
            if(parameters.size()==static_cast<int>(UePosCommProtocolArch::UeCommandNumberOfParameters::ACK_CMD_GET_NETWORK_SETTINGS))
            {
                QString clientHostname=parameters[2].toString();
                QString clientAddress=parameters[0].toString();
                QString clientPort=QString::number(parameters[1].toInt());
                QString clientOS=parameters[3].toString();

                this->ueSlotAddEventInfoLog(UeLogEntryType::INFO,
                                            tr("Acknowledge").append(" ")
                                                             .append(UePOSCommProtocol::ueCommandToString(executedCommand))
                                                             .append(" ")
                                                             .append(tr("from"))
                                                             .append(" ")
                                                             .append(clientHostname)
                                                             .append(" ")
                                                             .append(tr("with IP address"))
                                                             .append(" ")
                                                             .append(clientAddress)
                                                             .append(" ")
                                                             .append(tr("using port"))
                                                             .append(" ")
                                                             .append(clientPort));

                dynamic_cast<UeConnectedClientsTableWidget*>(this->ueConnectedClientsTableWidget())->ueConnectedClientsTableView()->ueAddConnectedClient(clientHostname,
                                                                                                                                                         QHostAddress(clientAddress),
                                                                                                                                                         clientPort,
                                                                                                                                                         clientOS);
            }
            else
            {
                //TODO handle invalid number of parameters error
            }   // if

            break;
        }   // case

        case UePosCommProtocolArch::UeCommand::ACK_CMD_DATABASE_GET_PLACES:
        {
            break;
        }   // case

        case UePosCommProtocolArch::UeCommand::CMD_DATABASE_GET_PLACES:
        {
            this->ueSlotAddEventInfoLog(UeLogEntryType::INFO,
                                        tr("Data fetched from database, command:").append(" ")
                                                                                  .append(UePOSCommProtocol::ueCommandToString(executedCommand))
                                                                                  .append(" ")
                                                                                  .append(tr("from"))
                                                                                  .append(" ")
                                                                                  .append(parameters[0].toString())
                                                                                  .append(" ")
                                                                                  .append(tr("at port"))
                                                                                  .append(" ")
                                                                                  .append(QString::number(parameters[1].toInt()))
                                                                                  .append(" ")
                                                                                  .append("(")
                                                                                  .append(parameters[2].toString())
                                                                                  .append(")"));
            break;
        }
    }   // switch
}   // ueSlotDataArrived

