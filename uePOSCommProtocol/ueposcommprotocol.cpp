#include "ueposcommprotocol.h"

UePOSCommProtocol::UePOSCommProtocol(QObject* parent)
    : QObject(parent)
{
}   // constructor

UePosCommProtocolArch::UeMessageType& UePOSCommProtocol::ueMessageType(const QByteArray& message,
                                                                       UePosCommProtocolArch::UeCommand& command)
{
    static UePosCommProtocolArch::UeMessageType messageType=UePosCommProtocolArch::UeMessageType::UE_INVALID;

    if(static_cast<quint8>(message.at(static_cast<int>(UePosCommProtocolArch::UeFieldIndexes::INDEX_MAGIC_NUMBER)))==static_cast<int>(UePosCommProtocolArch::UeHeader::MAGIC_NUMBER))
    {
        switch(static_cast<quint8>(message.at(static_cast<int>(UePosCommProtocolArch::UeFieldIndexes::INDEX_PACKET_MODE))))
        {
            case static_cast<quint8>(UePosCommProtocolArch::UeHeader::COMMAND_MODE):
            {
                messageType=UePosCommProtocolArch::UeMessageType::UE_COMMAND;

                command=static_cast<UePosCommProtocolArch::UeCommand>(message.at(static_cast<int>(UePosCommProtocolArch::UeFieldIndexes::INDEX_COMMAND)));

                break;
            }   // case

            case static_cast<quint8>(UePosCommProtocolArch::UeHeader::DATA_MODE):
            {
                messageType=UePosCommProtocolArch::UeMessageType::UE_DATA;

                break;
            }   // case

            case static_cast<quint8>(UePosCommProtocolArch::UeHeader::ACK_COMMAND_MODE):
            {
                messageType=UePosCommProtocolArch::UeMessageType::UE_ACK_COMMAND;

                break;
            }   // case
        }   // switch
    }   // if

    return messageType;
}   // ueMessageType

const QByteArray& UePOSCommProtocol::ueEncodeCommand(const UePosCommProtocolArch::UeCommand& command,
                                                     const QList<QVariant>& data,
                                                     quint32& dataSize)
{
    static QByteArray message=QByteArray();
    QByteArray hostInfo=QByteArray();
    dataSize=static_cast<quint32>(data.size());

    message.clear();
    message.append(static_cast<char>(UePosCommProtocolArch::UeHeader::MAGIC_NUMBER));
    message.append(static_cast<char>(UePosCommProtocolArch::UeHeader::COMMAND_MODE));

    switch(command)
    {
        case UePosCommProtocolArch::UeCommand::CMD_GET_NETWORK_SETTINGS:
        {
            message.append(static_cast<char>(UePosCommProtocolArch::UeCommand::CMD_GET_NETWORK_SETTINGS));

            hostInfo.append(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorStart::NETWORK_INFO_IP_ADDRESS));
            hostInfo.append(data.at(static_cast<int>(UePosCommProtocolArch::UeFieldIndexes::INDEX_NETWORK_IP_ADDRESS)).toByteArray());
            hostInfo.append(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorEnd::NETWORK_INFO_IP_ADDRESS));

            hostInfo.append(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorStart::NETWORK_INFO_PORT));
            hostInfo.append(data.at(static_cast<int>(UePosCommProtocolArch::UeFieldIndexes::INDEX_NETWORK_PORT)).toByteArray());
            hostInfo.append(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorEnd::NETWORK_INFO_PORT));

            message.append(hostInfo);

            break;
        }   // case

        case UePosCommProtocolArch::UeCommand::CMD_INVALID_COMMAND:
        {
            message.clear();

            break;
        }   // case

        case UePosCommProtocolArch::UeCommand::ACK_CMD_GET_NETWORK_SETTINGS:
        {
            message.append(static_cast<char>(UePosCommProtocolArch::UeCommand::ACK_CMD_GET_NETWORK_SETTINGS));

            hostInfo.append(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorStart::NETWORK_INFO_IP_ADDRESS));
            hostInfo.append(data.at(static_cast<int>(UePosCommProtocolArch::UeFieldIndexes::INDEX_NETWORK_IP_ADDRESS)).toByteArray());
            hostInfo.append(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorEnd::NETWORK_INFO_IP_ADDRESS));

            hostInfo.append(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorStart::NETWORK_INFO_PORT));
            hostInfo.append(data.at(static_cast<int>(UePosCommProtocolArch::UeFieldIndexes::INDEX_NETWORK_PORT)).toByteArray());
            hostInfo.append(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorEnd::NETWORK_INFO_PORT));

            hostInfo.append(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorStart::HOSTNAME_INFO));
            hostInfo.append(data.at(static_cast<int>(UePosCommProtocolArch::UeFieldIndexes::INDEX_NETWORK_HOSTNAME)).toByteArray());
            hostInfo.append(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorEnd::HOSTNAME_INFO));

            hostInfo.append(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorStart::HOST_OS));
            hostInfo.append(data.at(static_cast<int>(UePosCommProtocolArch::UeFieldIndexes::INDEX_NETWORK_CLIENT_OS)).toByteArray());
            hostInfo.append(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorEnd::HOST_OS));

            message.append(hostInfo);

            break;
        }   // case

        case UePosCommProtocolArch::UeCommand::CMD_DATABASE_GET_PLACES:
        {
            message.append(static_cast<char>(UePosCommProtocolArch::UeCommand::CMD_DATABASE_GET_PLACES));

            hostInfo.append(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorStart::NETWORK_INFO_IP_ADDRESS));
            hostInfo.append(data.at(static_cast<int>(UePosCommProtocolArch::UeFieldIndexes::INDEX_NETWORK_IP_ADDRESS)).toByteArray());
            hostInfo.append(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorEnd::NETWORK_INFO_IP_ADDRESS));

            hostInfo.append(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorStart::NETWORK_INFO_PORT));
            hostInfo.append(data.at(static_cast<int>(UePosCommProtocolArch::UeFieldIndexes::INDEX_NETWORK_PORT)).toByteArray());
            hostInfo.append(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorEnd::NETWORK_INFO_PORT));

            hostInfo.append(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorStart::HOSTNAME_INFO));
            hostInfo.append(data.at(static_cast<int>(UePosCommProtocolArch::UeFieldIndexes::INDEX_NETWORK_HOSTNAME)).toByteArray());
            hostInfo.append(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorEnd::HOSTNAME_INFO));

            message.append(hostInfo);

            break;
        }   // case

        case UePosCommProtocolArch::UeCommand::ACK_CMD_DATABASE_GET_PLACES:
        {
            message.append(static_cast<char>(UePosCommProtocolArch::UeCommand::ACK_CMD_DATABASE_GET_PLACES));

            message.append(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorStart::NETWORK_INFO_IP_ADDRESS));
            message.append(data.at(static_cast<int>(UePosCommProtocolArch::UeFieldIndexes::INDEX_NETWORK_IP_ADDRESS)).toByteArray());
            message.append(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorEnd::NETWORK_INFO_IP_ADDRESS));

            message.append(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorStart::NETWORK_INFO_PORT));
            message.append(data.at(static_cast<int>(UePosCommProtocolArch::UeFieldIndexes::INDEX_NETWORK_PORT)).toByteArray());
            message.append(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorEnd::NETWORK_INFO_PORT));

            message.append(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorStart::HOSTNAME_INFO));
            message.append(data.at(static_cast<int>(UePosCommProtocolArch::UeFieldIndexes::INDEX_NETWORK_HOSTNAME)).toByteArray());
            message.append(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorEnd::HOSTNAME_INFO));

            message.append(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorStart::TABLE_PLACES_INFO));
            message.append(data.at(3).toByteArray());
            message.append(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorEnd::TABLE_PLACES_INFO));

            break;
        }   // case
    }   // switch

    return message;
}   // encodeCommand

const UePosCommProtocolArch::UeCommand& UePOSCommProtocol::ueDecodeCommand(const QByteArray& message,
                                                                           QList<QVariant>& data)
{
    static UePosCommProtocolArch::UeCommand command;
    QByteArray hostInfo=QByteArray();

    if(message.size()>0&&UePOSCommProtocol::ueMessageType(message,
                                                          command)==UePosCommProtocolArch::UeMessageType::UE_COMMAND)
    {
        switch(command)
        {
            case UePosCommProtocolArch::UeCommand::CMD_GET_NETWORK_SETTINGS:
            {
                int indexStartIpAddress=message.indexOf(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorStart::NETWORK_INFO_IP_ADDRESS))+1;
                int indexEndIpAddress=message.indexOf(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorEnd::NETWORK_INFO_IP_ADDRESS));
                int indexStartPort=message.indexOf(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorStart::NETWORK_INFO_PORT))+1;
                int indexEndPort=message.indexOf(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorEnd::NETWORK_INFO_PORT));

                data.append(message.mid(indexStartIpAddress,
                                        indexEndIpAddress-indexStartIpAddress));
                data.append(message.mid(indexStartPort,
                                        indexEndPort-indexStartPort));

                break;
            }   // case

            case UePosCommProtocolArch::UeCommand::CMD_INVALID_COMMAND:
            {
                break;
            }   // case

            case UePosCommProtocolArch::UeCommand::ACK_CMD_GET_NETWORK_SETTINGS:
            {
                int indexStartIpAddress=message.indexOf(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorStart::NETWORK_INFO_IP_ADDRESS))+1;
                int indexEndIpAddress=message.indexOf(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorEnd::NETWORK_INFO_IP_ADDRESS));
                int indexStartPort=message.indexOf(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorStart::NETWORK_INFO_PORT))+1;
                int indexEndPort=message.indexOf(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorEnd::NETWORK_INFO_PORT));
                int indexStartHostname=message.indexOf(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorStart::HOSTNAME_INFO))+1;
                int indexEndHostname=message.indexOf(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorEnd::HOSTNAME_INFO));
                int indexStartHostOS=message.indexOf(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorStart::HOST_OS))+1;
                int indexEndHostOS=message.indexOf(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorEnd::HOST_OS));

                data.append(message.mid(indexStartIpAddress,
                                        indexEndIpAddress-indexStartIpAddress));
                data.append(message.mid(indexStartPort,
                                        indexEndPort-indexStartPort));
                data.append(message.mid(indexStartHostname,
                                        indexEndHostname-indexStartHostname));
                data.append(message.mid(indexStartHostOS,
                                        indexEndHostOS-indexStartHostOS));

                break;
            }   // case

            case UePosCommProtocolArch::UeCommand::CMD_DATABASE_GET_PLACES:
            {
                int indexStartIpAddress=message.indexOf(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorStart::NETWORK_INFO_IP_ADDRESS))+1;
                int indexEndIpAddress=message.indexOf(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorEnd::NETWORK_INFO_IP_ADDRESS));
                int indexStartPort=message.indexOf(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorStart::NETWORK_INFO_PORT))+1;
                int indexEndPort=message.indexOf(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorEnd::NETWORK_INFO_PORT));
                int indexStartHostname=message.indexOf(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorStart::HOSTNAME_INFO))+1;
                int indexEndHostname=message.indexOf(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorEnd::HOSTNAME_INFO));

                data.append(message.mid(indexStartIpAddress,
                                        indexEndIpAddress-indexStartIpAddress));
                data.append(message.mid(indexStartPort,
                                        indexEndPort-indexStartPort));
                data.append(message.mid(indexStartHostname,
                                        indexEndHostname-indexStartHostname));

                break;
            }   // case

            case UePosCommProtocolArch::UeCommand::ACK_CMD_DATABASE_GET_PLACES:
            {
                int indexStartIpAddress=message.indexOf(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorStart::NETWORK_INFO_IP_ADDRESS))+1;
                int indexEndIpAddress=message.indexOf(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorEnd::NETWORK_INFO_IP_ADDRESS));
                int indexStartPort=message.indexOf(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorStart::NETWORK_INFO_PORT))+1;
                int indexEndPort=message.indexOf(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorEnd::NETWORK_INFO_PORT));
                int indexStartHostname=message.indexOf(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorStart::HOSTNAME_INFO))+1;
                int indexEndHostname=message.indexOf(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorEnd::HOSTNAME_INFO));
                int indexStartSqlData=message.indexOf(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorStart::TABLE_PLACES_INFO))+1;
                int indexEndSqlData=message.lastIndexOf(static_cast<char>(UePosCommProtocolArch::UeMessageDescriptorEnd::TABLE_PLACES_INFO));

                data.append(message.mid(indexStartIpAddress,
                                        indexEndIpAddress-indexStartIpAddress));
                data.append(message.mid(indexStartPort,
                                        indexEndPort-indexStartPort));
                data.append(message.mid(indexStartHostname,
                                        indexEndHostname-indexStartHostname));
                data.append(message.mid(indexStartSqlData,
                                        indexEndSqlData-indexStartSqlData));

                break;
            }   // case
        }   // switch
    }   // if

    return command;
}   // ueDecodeCommand

const QString& UePOSCommProtocol::ueCommandToString(const UePosCommProtocolArch::UeCommand& command)
{
    static QString result;

    switch(command)
    {
        case UePosCommProtocolArch::UeCommand::CMD_GET_NETWORK_SETTINGS:
        {
            result="CMD_GET_NETWORK_SETTINGS";

            break;
        }   // case

        case UePosCommProtocolArch::UeCommand::CMD_INVALID_COMMAND:
        {
            result="CMD_INVALID_COMMAND";

            break;
        }   // case

        case UePosCommProtocolArch::UeCommand::ACK_CMD_GET_NETWORK_SETTINGS:
        {
            result="ACK_CMD_GET_NETWORK_SETTINGS";

            break;
        }   // case

        case UePosCommProtocolArch::UeCommand::CMD_DATABASE_GET_PLACES:
        {
            result="CMD_DATABASE_GET_PLACES";

            break;
        }   // case

        case UePosCommProtocolArch::UeCommand::ACK_CMD_DATABASE_GET_PLACES:
        {
            result="ACK_CMD_DATABASE_GET_PLACES";

            break;
        }   // case
    }   // switch

    return result;
}   // ueCommandToString
