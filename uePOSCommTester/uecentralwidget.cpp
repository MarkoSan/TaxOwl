#include "uecentralwidget.h"

UeCentralWidget::UeCentralWidget(QWidget *parent)
    : QWidget(parent)
{
    this->setLayout(new QVBoxLayout());

    this->ueSetButtonsLayout(new QHBoxLayout());
    this->ueSetOptionsLayout(new QHBoxLayout());

    this->ueSetCommTextEditor(new UeLogWindow(this));
    this->ueCommTextEditor()->setReadOnly(true);


    this->ueSetHexCheckBox(new QCheckBox(tr("Hex mode"),
                                         this));
    this->ueSetDirectSendCheckBox(new QCheckBox(tr("Direct send"),
                                                this));

    this->ueOptionsLayout()->addWidget(this->ueHexCheckBox());
    this->ueOptionsLayout()->addWidget(this->ueDirectSendCheckBox());

    this->ueSetSendButton(new QPushButton(tr("Send"),
                                          this));
    this->ueSetClearButton(new QPushButton(tr("Clear"),
                                           this));
    this->ueSetQuitButton(new QPushButton(tr("Quit"),
                                           this));

    dynamic_cast<QHBoxLayout*>(this->ueButtonsLayout())->addWidget(this->ueSendButton());
    dynamic_cast<QHBoxLayout*>(this->ueButtonsLayout())->addWidget(this->ueClearButton());
    dynamic_cast<QHBoxLayout*>(this->ueButtonsLayout())->addWidget(this->ueQuitButton());

    dynamic_cast<QVBoxLayout*>(this->layout())->addWidget(this->ueCommTextEditor());
    dynamic_cast<QVBoxLayout*>(this->layout())->addLayout(this->ueOptionsLayout());
    dynamic_cast<QVBoxLayout*>(this->layout())->addLayout(this->ueButtonsLayout());

    connect(this->ueHexCheckBox(),
            SIGNAL(stateChanged(int)),
            this,
            SLOT(ueSlotHexModeClick(int)));

    connect(this->ueDirectSendCheckBox(),
            SIGNAL(stateChanged(int)),
            this,
            SLOT(ueSlotDirectSendClick(int)));

    connect(this->ueSendButton(),
            SIGNAL(clicked()),
            this,
            SLOT(ueSlotSendButtonClick()));
    connect(this->ueClearButton(),
            SIGNAL(clicked()),
            this,
            SLOT(ueSlotClearButtonClick()));
    connect(this->ueQuitButton(),
            SIGNAL(clicked()),
            this,
            SLOT(ueSlotQuitButtonClick()));

    this->ueSetNetworkDiscoverySocket(new UeNetworkDiscoverySocket(this));
    connect(this->ueNetworkDiscoverySocket(),
            SIGNAL(readyRead()),
            this,
            SLOT(ueSlotReadNetworkDiscoverySocketData()));
    connect(this->ueNetworkDiscoverySocket(),
            SIGNAL(connected()),
            this,
            SLOT(ueSlotNetworkDiscoverySocketConnected()));
    connect(this->ueNetworkDiscoverySocket(),
            SIGNAL(disconnected()),
            this,
            SLOT(ueSlotNetworkDiscoverySocketDisconnected()));
    connect(this->ueNetworkDiscoverySocket(),
            SIGNAL(error(QAbstractSocket::SocketError)),
            this,
            SLOT(ueSlotNetworkDiscoverySocketError(QAbstractSocket::SocketError)));
    connect(this->ueNetworkDiscoverySocket(),
            SIGNAL(hostFound()),
            this,
            SLOT(ueSlotNetworkDiscoverySocketHostFound()));
    connect(this->ueNetworkDiscoverySocket(),
            SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this,
            SLOT(ueSlotNetworkDiscoverySocketStateChanged(QAbstractSocket::SocketState)));
    this->ueNetworkDiscoverySocket()->bind(UeDefaults::UDP_NETWORK_INFORMATION_SOCKET_PORT,
                                           QUdpSocket::ShareAddress);

    this->ueSetDataTransferSocket(new UeDataTransferSocket(this));
    connect(this->ueDataTransferSocket(),
            SIGNAL(readyRead()),
            this,
            SLOT(ueSlotReadDataTransferSocketData()));
    connect(this->ueDataTransferSocket(),
            SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this,
            SLOT(ueSlotDataTransferSocketStateChanged(QAbstractSocket::SocketState)));
    connect(this->ueDataTransferSocket(),
            SIGNAL(hostFound()),
            this,
            SLOT(ueSlotDataTransferSocketHostFound()));
    connect(this->ueDataTransferSocket(),
            SIGNAL(connected()),
            this,
            SLOT(ueSlotDataTransferSocketConnected()));
    connect(this->ueDataTransferSocket(),
            SIGNAL(disconnected()),
            this,
            SLOT(ueSlotDataTransferSocketDisconnected()));

    this->ueSetDataReaderTask(new UeDataReaderTask(this->ueDataTransferSocket(),
                                                   this));
}   // constructor

void UeCentralWidget::ueSlotHexModeClick(int state)
{
    Q_UNUSED(state);
}   // ueSlotHexModeClick

void UeCentralWidget::ueSlotDirectSendClick(int state)
{
    this->ueSendButton()->setVisible(state==Qt::Checked?false:true);
}   // ueSlotDirectSendClick

void UeCentralWidget::ueSlotSendButtonClick()
{
}   // ueSlotSendButtonClick

void UeCentralWidget::ueSlotClearButtonClick()
{
//    this->ueCommandsEditor()->clear();
    this->ueCommTextEditor()->clear();
}   // ueSlotClearButtonClick

void UeCentralWidget::ueSlotQuitButtonClick()
{
    qApp->quit();
}   // ueSelotCloseButtonClick

void UeCentralWidget::ueSlotReadNetworkDiscoverySocketData()
{
    QByteArray networkDiscoveryMessage;
    QList<QVariant> data;
    QString printOut;

    while(this->ueNetworkDiscoverySocket()->hasPendingDatagrams())
    {
        networkDiscoveryMessage.resize(static_cast<int>(this->ueNetworkDiscoverySocket()->pendingDatagramSize()));
        if(this->ueNetworkDiscoverySocket()->readDatagram(networkDiscoveryMessage.data(),
                                                          networkDiscoveryMessage.size())>0)
        {
            UePosCommProtocolArch::UeCommand command=UePOSCommProtocol::ueDecodeCommand(networkDiscoveryMessage,
                                                                                        data);

            switch(command)
            {
                case UePosCommProtocolArch::UeCommand::CMD_GET_NETWORK_SETTINGS:
                {
                    if(data.size()==static_cast<int>(UePosCommProtocolArch::UeCommandNumberOfParameters::CMD_GET_NETWORK_SETTINGS))
                    {
                        QHostAddress serverAddress=QHostAddress(data[0].toString());
                        quint16 serverPort=static_cast<quint16>(data[1].toInt());

                        printOut.append(tr("Incoming message ").append(UePOSCommProtocol::ueCommandToString(command))
                                                               .append(" ")
                                                               .append(tr("from "))
                                                               .append(serverAddress.toString())
                                                               .append(tr(" using port "))
                                                               .append(QString::number(serverPort)));

                        if(this->ueDataTransferSocket()->state()==QAbstractSocket::UnconnectedState)
                        {
                            this->ueDataTransferSocket()->connectToHost(serverAddress,
                                                                        serverPort);
                        }   // if
                    }
                    else
                    {
                        printOut.append(tr("Invalid message size"));
                    }   // if

                    break;
                }   // case

                case UePosCommProtocolArch::UeCommand::CMD_INVALID_COMMAND:
                {
                    printOut.append(tr("Invalid message received. Ignoring"));

                    break;
                }   // case

                case UePosCommProtocolArch::UeCommand::ACK_CMD_GET_NETWORK_SETTINGS:
                {
                    if(data.size()==static_cast<int>(UePosCommProtocolArch::UeCommandNumberOfParameters::ACK_CMD_GET_NETWORK_SETTINGS))
                    {
                        QHostAddress clientAddress=QHostAddress(data[0].toString());
                        quint16 clientPort=static_cast<quint16>((data[1].toInt()));
                        QString clientHostname=data[2].toString();

                        printOut.append(tr("Incoming message ").append(UePOSCommProtocol::ueCommandToString(command))
                                                               .append(" ")
                                                               .append(tr("from"))
                                                               .append(" ")
                                                               .append(clientHostname)
                                                               .append(" ")
                                                               .append(tr("with IP address"))
                                                               .append(" ")
                                                               .append(clientAddress.toString())
                                                               .append(" ")
                                                               .append(tr(" using port "))
                                                               .append(QString::number(clientPort)));
                    }   // if

                    break;
                }   // case

                case UePosCommProtocolArch::UeCommand::CMD_DATABASE_GET_PLACES:
                {
                    break;
                }   // case

                case UePosCommProtocolArch::UeCommand::ACK_CMD_DATABASE_GET_PLACES:
                {
                    break;
                }   // case
            }   // switch

            this->ueCommTextEditor()->appendPlainText(this->ueCommTextEditor()->ueCreateLogEntry(UeLogEntryType::INFO,
                                                                                                 printOut));
        }   // if
    }   // while
}   // ueSlotReadSocketData

void UeCentralWidget::ueSlotReadDataTransferSocketData()
{
    QList<QVariant> incomingData=QList<QVariant>();
    QByteArray incomingMessage=this->ueDataTransferSocket()->readAll();
    int incomingMessageSize=incomingMessage.size();

    UePosCommProtocolArch::UeCommand incomingCommand=UePOSCommProtocol::ueDecodeCommand(incomingMessage,
                                                                                        incomingData);

    switch(incomingCommand)
    {
        case UePosCommProtocolArch::UeCommand::ACK_CMD_DATABASE_GET_PLACES:
        {
            if(incomingMessageSize>0)
            {
                if(incomingData.size()==static_cast<int>(UePosCommProtocolArch::UeCommandNumberOfParameters::ACK_CMD_DATABASE_GET_PLACES))
                {
                    this->ueCommTextEditor()->appendPlainText(this->ueCommTextEditor()->ueCreateLogEntry(UeLogEntryType::INFO,
                                                                                                         tr("Received").append(" ")
                                                                                                                       .append(UePOSCommProtocol::ueCommandToString(incomingCommand))
                                                                                                                       .append(" ")
                                                                                                                       .append("of size")
                                                                                                                       .append(" ")
                                                                                                                       .append(QString::number(incomingMessageSize))
                                                                                                                       .append(" ")
                                                                                                                       .append(tr("bytes"))
                                                                                                                       .append(" ")
                                                                                                                       .append(tr("sent from server"))));

                    emit this->ueSignalNewDataArrivedPlaces(QJsonDocument::fromBinaryData(incomingData[3].toByteArray()));
                }
                else
                {
                }   // if
            }
            else
            {
                this->ueCommTextEditor()->appendPlainText(this->ueCommTextEditor()->ueCreateLogEntry(UeLogEntryType::ERROR,
                                                                                                     tr("Error").append(" ")
                                                                                                                .append(this->ueDataTransferSocket()->errorString())
                                                                                                                .append(" ")
                                                                                                                .append(tr("receiveing incoming data"))));
            }   // if

            break;
        }   // case

        case UePosCommProtocolArch::UeCommand::ACK_CMD_GET_NETWORK_SETTINGS:
        {
            break;
        }   // case

        case UePosCommProtocolArch::UeCommand::CMD_DATABASE_GET_PLACES:
        {
            break;
        }   // case

        case UePosCommProtocolArch::UeCommand::CMD_GET_NETWORK_SETTINGS:
        {
            break;
        }   // case

        case UePosCommProtocolArch::UeCommand::CMD_INVALID_COMMAND:
        {
            break;
        }   // case
    }   // switch
}   // ueSlotReadCommunicationsSocketData

void UeCentralWidget::ueSlotDataTransferSocketStateChanged(QAbstractSocket::SocketState socketState)
{
    this->ueCommTextEditor()->appendPlainText(this->ueCommTextEditor()->ueCreateLogEntry(UeLogEntryType::WARNING,
                                                                                         tr("Data transfer socket socket state changed to").append(" ")
                                                                                                                                           .append(QString::number(socketState))));
}   // ueSlotCommunicationsSocketStateChanged

void UeCentralWidget::ueSlotDataTransferSocketHostFound()
{
    this->ueCommTextEditor()->appendPlainText(this->ueCommTextEditor()->ueCreateLogEntry(UeLogEntryType::WARNING,
                                                                                         tr("Data transfer socket found host")));
}   // ueSlotCommunicationsSocketHostFound

void UeCentralWidget::ueSlotDataTransferSocketConnected()
{
    QByteArray data=QByteArray();
    QList<QVariant> parameters=QList<QVariant>();
    quint32 dataSize=0;

    parameters.append(this->ueDataTransferSocket()->localAddress().toString());
    parameters.append(QString::number(this->ueDataTransferSocket()->localPort()));
    parameters.append(QHostInfo::localHostName());
    parameters.append(QSysInfo::prettyProductName());

    this->ueCommTextEditor()->appendPlainText(this->ueCommTextEditor()->ueCreateLogEntry(UeLogEntryType::INFO,
                                                                                         tr("Data transfer socket connected to server")));
    if(this->ueDataTransferSocket()->write(UePOSCommProtocol::ueEncodeCommand(UePosCommProtocolArch::UeCommand::ACK_CMD_GET_NETWORK_SETTINGS,
                                                                              parameters,
                                                                              dataSize))>0)
    {
        this->ueCommTextEditor()->appendPlainText(this->ueCommTextEditor()->ueCreateLogEntry(UeLogEntryType::INFO,
                                                                                             tr("Message").append(" ")
                                                                                                          .append(UePOSCommProtocol::ueCommandToString(UePosCommProtocolArch::UeCommand::ACK_CMD_GET_NETWORK_SETTINGS))
                                                                                                          .append(" ")
                                                                                                          .append(tr("replied to server"))));
    }
    else
    {
        this->ueCommTextEditor()->appendPlainText(this->ueCommTextEditor()->ueCreateLogEntry(UeLogEntryType::ERROR,
                                                                                             tr("Error sending message").append(" ")
                                                                                                                        .append(UePOSCommProtocol::ueCommandToString(UePosCommProtocolArch::UeCommand::ACK_CMD_GET_NETWORK_SETTINGS))
                                                                                                                        .append(" ")
                                                                                                                        .append(tr("reply to server"))
                                                                                                                        .append(" ")
                                                                                                                        .append(QString::number(this->ueNetworkDiscoverySocket()->error()))
                                                                                                                        .append(" ")
                                                                                                                        .append("(")
                                                                                                                        .append(this->ueNetworkDiscoverySocket()->errorString())
                                                                                                                        .append(")")));
    }   // if
}   // ueSlotCommunicationsSocketConnected

void UeCentralWidget::ueSlotDataTransferSocketDisconnected()
{
    this->ueCommTextEditor()->appendPlainText(this->ueCommTextEditor()->ueCreateLogEntry(UeLogEntryType::INFO,
                                                                                         tr("Data transfer socket disconnected from server")));
}   // ueSlotCommunicationsSocketDisconnected

void UeCentralWidget::ueSlotNetworkDiscoverySocketConnected()
{
    this->ueCommTextEditor()->appendPlainText(this->ueCommTextEditor()->ueCreateLogEntry(UeLogEntryType::INFO,
                                                                                         tr("Network discovery socket connected")));
}   // ueSlotNetworkDiscoverySocketConnected

void UeCentralWidget::ueSlotNetworkDiscoverySocketDisconnected()
{
    this->ueCommTextEditor()->appendPlainText(this->ueCommTextEditor()->ueCreateLogEntry(UeLogEntryType::INFO,
                                                                                         tr("Network discovery socket disconnected")));
}   // ueSlotNetworkDiscoverySocketDisconnected

void UeCentralWidget::ueSlotNetworkDiscoverySocketError(QAbstractSocket::SocketError socketError)
{
    this->ueCommTextEditor()->appendPlainText(this->ueCommTextEditor()->ueCreateLogEntry(UeLogEntryType::ERROR,
                                                                                         tr("Network discovery socket error").append(" ")
                                                                                                                             .append(QString::number(socketError))
                                                                                                                             .append(" ")
                                                                                                                             .append("(")
                                                                                                                             .append(this->ueNetworkDiscoverySocket()->errorString())
                                                                                                                             .append(")")));
}   // ueSlotNetworkDiscoverySocketError

void UeCentralWidget::ueSlotNetworkDiscoverySocketHostFound()
{
    this->ueCommTextEditor()->appendPlainText(this->ueCommTextEditor()->ueCreateLogEntry(UeLogEntryType::INFO,
                                                                                         tr("Network discovery socket host found")));
}   // ueSlotNetworkDiscoverySocketHostFound

void UeCentralWidget::ueSlotNetworkDiscoverySocketStateChanged(QAbstractSocket::SocketState socketState)
{
    this->ueCommTextEditor()->appendPlainText(this->ueCommTextEditor()->ueCreateLogEntry(UeLogEntryType::WARNING,
                                                                                         tr("Network discovery socket new state").append(" ")
                                                                                                                                 .append(QString::number(socketState))));
}   // ueSlotNetworkDiscoverySocketStateChanged
