#include "uetcpserver.h"

UeTcpServer::UeTcpServer(QObject* parent,
                         UeSettings* const settings)
    : QTcpServer(parent),
      m_ueSettings(settings)
{
}   // constructor

UeTcpServer::~UeTcpServer()
{
}   // destructor

bool UeTcpServer::ueStart(const quint16& port)
{
    bool result=false;
    QString logText=QString();

    if(!this->isListening())
    {
        if(this->listen(QHostAddress::AnyIPv4,
                        port))
        {
            logText=tr("Server listening using network address")
                    .append(" ")
                    .append(this->ueServerIPv4().toString())
                    .append(" ")
                    .append(tr("to address(es)"))
                    .append(" ")
                    .append(this->serverAddress().toString())
                    .append(" ")
                    .append(tr("on port"))
                    .append(" ")
                    .append(QString::number(this->serverPort()));

                    result=true;

                    emit this->ueSignalEmitLogEvent(UeLogEntryType::INFO,
                                                    logText);
        }
        else
        {
            logText=this->errorString()
                    .append(" ")
                    .append(tr("with error code"))
                    .append(" ")
                    .append(this->serverError());

            emit this->ueSignalEmitLogEvent(UeLogEntryType::ERROR,
                                            logText);
        }   // if
    }
    else
    {
        logText=tr("Server not started, since it is already listening from")
                .append(" ")
                .append(this->ueServerIPv4().toString())
                .append(" ")
                .append(tr("to address(es)"))
                .append(this->serverAddress().toString())
                .append(" ")
                .append(tr("on port"))
                .append(" ")
                .append(QString::number(this->serverPort()));

        emit this->ueSignalEmitLogEvent(UeLogEntryType::WARNING,
                                        logText);
    }   // if

    return result;
}   // ueStart

void UeTcpServer::ueRestart(const QHostAddress& address,
                            const quint16& port)
{
    QString logText;

    if(this->ueServerIPv4()==address&&port==this->serverPort())
    {
        emit this->ueSignalEmitLogEvent(UeLogEntryType::WARNING,
                                        tr("Server not restarted"));
    }
    else
    {
        emit this->ueSignalEmitLogEvent(UeLogEntryType::INFO,
                                        tr("Restarting server"));
        this->close();
        if(this->listen(address,
                        port))
        {
            emit this->ueSignalEmitLogEvent(UeLogEntryType::INFO,
                                            tr("Server restarted using IP address").append(" ")
                                                                                   .append(address.toString())
                                                                                   .append(" ")
                                                                                   .append(tr("using port"))
                                                                                   .append(" ")
                                                                                   .append(QString::number(port)));
        }
        else
        {
            emit this->ueSignalEmitLogEvent(UeLogEntryType::INFO,
                                            tr("Server could not be restarted using IP address").append(" ")
                                                                                                .append(address.toString())
                                                                                                .append(" ")
                                                                                                .append(tr("using port"))
                                                                                                .append(" ")
                                                                                                .append(QString::number(port)));
        }   // if
    }   // if
}   // ueRestart

const QHostAddress& UeTcpServer::ueServerIPv4() const
{
    static QHostAddress currentAddress=QHostAddress();

    foreach(const QHostAddress &address,
            QNetworkInterface::allAddresses())
    {
        if(address.protocol()==QAbstractSocket::IPv4Protocol/*&&address!=QHostAddress(QHostAddress::LocalHost)*/)
        {
            currentAddress=address;
        }   // if
    }   // foreach

    return currentAddress;
}

void UeTcpServer::incomingConnection(qintptr socketDescriptor)
{
    UeClient* client=new UeClient(this,
                                  this->ueSettings());

    client->ueSetSocket(socketDescriptor);


    connect(client,
            SIGNAL(ueSignalDataArrived(const UePosCommProtocolArch::UeCommand&,
                                       const QByteArray&,
                                       const QList<QVariant>&)),
            this,
            SLOT(ueSlotDataArrived(const UePosCommProtocolArch::UeCommand&,
                                   const QByteArray&,
                                   const QList<QVariant>&)));


    connect(client,
            SIGNAL(ueSignalAddEventInfoLog(const UeLogEntryType&,
                                           const QString&)),
            this,
            SLOT(ueSlotAddEventInfoLog(const UeLogEntryType&,
                                       const QString&)));
}   // incomingConnection

void UeTcpServer::ueSlotDataArrived(const UePosCommProtocolArch::UeCommand& executedCommand,
                                    const QByteArray& fetchedData,
                                    const QList<QVariant>& parameters)
{
    emit this->ueSignalDataArrived(executedCommand,
                                   fetchedData,
                                   parameters);
}

void UeTcpServer::ueSlotAddEventInfoLog(const UeLogEntryType& messageType,
                                        const QString& message)
{
    emit this->ueSignalEmitLogEvent(messageType,
                                    message);
}   // ueSlotAddEventInfoLog
