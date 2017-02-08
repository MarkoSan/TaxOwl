#include "ueclient.h"

UeClient::UeClient(QObject *parent,
                   UeSettings* const settings)
    : QObject(parent)
{
    qRegisterMetaType<UePosCommProtocolArch::UeCommand>("UePosCommProtocolArch::UeCommand");

    QThreadPool::globalInstance()->setMaxThreadCount(10);

    this->ueSetSettings(settings);
}   // constructor

void UeClient::ueSetSocket(const qintptr& socketDescriptor)
{
    this->m_ueSocket=new QTcpSocket(this);

    connect(this->ueSocket(),
            SIGNAL(connected()),
            this,
            SLOT(ueSlotConnected()));
    connect(this->ueSocket(),
            SIGNAL(disconnected()),
            this,
            SLOT(ueSlotDisconnected()));
    connect(this->ueSocket(),
            SIGNAL(readyRead()),
            this,
            SLOT(ueSlotReadyRead()));
    connect(this->ueSocket(),
            SIGNAL(readChannelFinished()),
            this,
            SLOT(ueSlotReadFinished()));

    this->ueSocket()->setSocketDescriptor(socketDescriptor);
}   // ueSetSocket

void UeClient::ueSlotConnected()
{
}   // ueSlotConnected

void UeClient::ueSlotDisconnected()
{
}   // ueSlotDisconnected

void UeClient::ueSlotReadyRead()
{
    QList<QVariant> incomingData=QList<QVariant>();
    QByteArray incomingMessage=this->ueSocket()->readAll();

    UePosCommProtocolArch::UeCommand incomingCommand=UePOSCommProtocol::ueDecodeCommand(incomingMessage,
                                                                                        incomingData);

    UeTask* ueTask=new UeTask(this->ueSettings()->ueDatabaseName(),
                              this->ueSettings()->ueDatabaseUsername(),
                              this->ueSettings()->ueDatabasePassword(),
                              this->ueSettings()->ueDatabaseServerAddress(),
                              this->ueSettings()->ueDatabaseServerPort(),
                              incomingCommand,
                              incomingData);

    connect(ueTask,
            SIGNAL(ueSignalTaskFinished(const UePosCommProtocolArch::UeCommand&,
                                        const QByteArray&,
                                        const QList<QVariant>&)),
            this,
            SLOT(ueSlotFetchData(const UePosCommProtocolArch::UeCommand&,
                                 const QByteArray&,
                                 const QList<QVariant>&)),
            Qt::QueuedConnection);

    QThreadPool::globalInstance()->start(ueTask);
}   // ueSlotReadyRead

void UeClient::ueSlotFetchData(const UePosCommProtocolArch::UeCommand& executedCommand,
                               const QByteArray& fetchedData,
                               const QList<QVariant>& parameters)
{
    quint32 dataSize;

    emit this->ueSignalDataArrived(executedCommand,
                                   fetchedData,
                                   parameters);

    switch(executedCommand)
    {
        case UePosCommProtocolArch::UeCommand::CMD_DATABASE_GET_PLACES:
        {
            QList<QVariant> data=parameters;

            data.append(fetchedData);

            QByteArray replyCommand=UePOSCommProtocol::ueEncodeCommand(UePosCommProtocolArch::UeCommand::ACK_CMD_DATABASE_GET_PLACES,
                                                                       data,
                                                                       dataSize);

            QDataStream outDataStream(this->ueSocket());

            outDataStream.setVersion(QDataStream::Qt_5_7);

            if(outDataStream.writeRawData(replyCommand,
                                          replyCommand.size())>0)
//            if(this->ueSocket()->write(replyCommand))
            {
                if(dataSize==static_cast<int>(UePosCommProtocolArch::UeCommandNumberOfParameters::ACK_CMD_DATABASE_GET_PLACES))
                {
                    emit this->ueSignalAddEventInfoLog(UeLogEntryType::INFO,
                                                       tr("Sending reply").append(" ")
                                                                          .append(UePOSCommProtocol::ueCommandToString(UePOSCommProtocol::ueDecodeCommand(replyCommand,
                                                                                                                                                          data)))
                                                                          .append(" ")
                                                                          .append(tr("to client"))
                                                                          .append(" ")
                                                                          .append(data.at(0).toString()
                                                                          .append(" ")
                                                                          .append("with port ")
                                                                          .append(" ")
                                                                          .append(data.at(1).toString())
                                                                          .append(" ")
                                                                          .append("(")
                                                                          .append(data.at(2).toString())
                                                                          .append(")")));
                }
                else
                {
                    //TODO handle invalid number of parameters error
                }   // if
            }
            else
            {
                emit this->ueSignalAddEventInfoLog(UeLogEntryType::ERROR,
                                                   tr("Error sending reply").append(" ")
                                                                            .append(UePOSCommProtocol::ueCommandToString(UePOSCommProtocol::ueDecodeCommand(replyCommand,
                                                                                                                                                            data)))
                                                                            .append(" ")
                                                                            .append(tr("to client"))
                                                                            .append(" ")
                                                                            .append(data.at(0).toString()
                                                                            .append(" ")
                                                                            .append("with port ")
                                                                            .append(" ")
                                                                            .append(data.at(1).toString())
                                                                            .append(" ")
                                                                            .append("(")
                                                                            .append(data.at(2).toString())
                                                                            .append(")"))
                                                                            .append(" ")
                                                                            .append(this->ueSocket()->errorString()));
            }   // if

            break;
        }   // case

        case UePosCommProtocolArch::UeCommand::CMD_INVALID_COMMAND:
        {
            break;
        }   // case

        case UePosCommProtocolArch::UeCommand::CMD_GET_NETWORK_SETTINGS:
        {
            break;
        }   // case

        case UePosCommProtocolArch::UeCommand::ACK_CMD_GET_NETWORK_SETTINGS:
        {
            break;
        }   // case

        case UePosCommProtocolArch::UeCommand::ACK_CMD_DATABASE_GET_PLACES:
        {
            break;
        }   // case
    }   // switch
}   // ueSlotFetchData

void UeClient::ueSlotReadFinished()
{
    qDebug() << Q_FUNC_INFO
             << "Read finished";
}   // ueSlotReadFinished
