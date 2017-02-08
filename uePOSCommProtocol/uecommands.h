#ifndef UECOMMANDS_H
#define UECOMMANDS_H

#include <QtGlobal>
#include <QString>

namespace UePosCommProtocolArch
{
    /*!
     * \enum UePosCommProtocolArch::UeCommand
     * \author Marko Frelih
     * \version alpha
     * \date 20/07/2016
     * \brief Protocol commands
     * \details a strongly typed enum class representing the commands in protocol datagram header
     */
    enum class UeCommand : quint8
    {
        CMD_INVALID_COMMAND=0xff,               /*!<0xff*/

        CMD_GET_NETWORK_SETTINGS=0x10,          /*!<0x00*/
        CMD_DATABASE_GET_PLACES=0x11,           /*!<0x11*/

        ACK_CMD_GET_NETWORK_SETTINGS=0x22,      /*!<0x22*/
        ACK_CMD_DATABASE_GET_PLACES=0x23,       /*!<0x23*/
    };   // UeCommand

    /*!
     * \enum UePosCommProtocolArch::UeMessageType
     * \author Marko Frelih
     * \version alpha
     * \date 20/07/2016
     * \brief Protocol message types
     * \details a strongly typed enum class representing the protocol message types
     */
    enum class UeMessageType : quint8
    {
        UE_INVALID=0x00,                        /*!<0x00*/
        UE_DATA=0x01,                           /*!<0x01*/
        UE_COMMAND=0x02,                        /*!<0x02*/
        UE_ACK_COMMAND=0x03                     /*!<0x03*/
    };  // UeDatagramType

    /*!
     * \enum UePosCommProtocolArch::UeFieldIndexes
     * \author Marko Frelih
     * \version alpha
     * \date 20/07/2016
     * \brief Protocol message fields indexes
     * \details a strongly typed enum class representing the protocol message fields indexes
     */
    enum class UeFieldIndexes : quint8
    {
        INDEX_MAGIC_NUMBER=0x00,                /*!<0x00*/
        INDEX_PACKET_MODE=0x01,                 /*!<0x01*/
        INDEX_COMMAND=0x02,                     /*!<0x02*/

        INDEX_NETWORK_IP_ADDRESS=0x00,          /*!<0x00*/
        INDEX_NETWORK_PORT=0x01,                /*!<0x01*/
        INDEX_NETWORK_HOSTNAME=0x02,            /*!<0x02*/
        INDEX_NETWORK_CLIENT_OS=0x03,           /*!<0x03*/
    };  // UeFieldIndexes

    /*!
     * \enum UePosCommProtocolArch::UeHeader
     * \author Marko Frelih
     * \version alpha
     * \date 20/07/2016
     * \brief Protocol message fields indexes
     * \details a strongly typed enum class representing values in protocol message header
     */
    enum class UeHeader : quint8
    {
        MAGIC_NUMBER=0xf8,                      /*!<0xf8*/
        COMMAND_MODE=0x00,                      /*!<0x00*/
        DATA_MODE=0x01,                         /*!<0x01*/
        ACK_COMMAND_MODE=0x02,                  /*!<0x02*/
    };  // UeHeader

    /*!
     * \enum UePosCommProtocolArch::UeMessageDescriptorStart
     * \author Marko Frelih
     * \version alpha
     * \date 20/07/2016
     * \brief Protocol message data start
     * \details a strongly typed enum class representing the protocol message data start
     */
    enum class UeMessageDescriptorStart : quint8
    {
        NETWORK_INFO_IP_ADDRESS=0x0a,           /*!<0x0a*/
        NETWORK_INFO_PORT=0x0b,                 /*!<0x0b*/
        HOSTNAME_INFO=0x0c,                     /*!<0x0c*/
        HOST_OS=0x0d,                           /*!<0x0d*/
        TABLE_PLACES_INFO=0x0f,                 /*!<0x0f*/
    };   // UeCommand

    /*!
     * \enum UePosCommProtocolArch::UeMessageDescriptorEnd
     * \author Marko Frelih
     * \version alpha
     * \date 20/07/2016
     * \brief Protocol message data end
     * \details a strongly typed enum class representing the protocol message data end
     */
    enum class UeMessageDescriptorEnd : quint8
    {
        NETWORK_INFO_IP_ADDRESS=0x80,           /*!<0x80*/
        NETWORK_INFO_PORT=0x81,                 /*!<0x81*/
        HOSTNAME_INFO=0x82,                     /*!<0x82*/
        HOST_OS=0x83,                           /*!<0x83*/
        TABLE_PLACES_INFO=0x84,                 /*!<0x84*/
    };   // UeCommand

    /*!
     * \enum UePosCommProtocolArch::UeCommandNumberOfParameters
     * \author Marko Frelih
     * \version alpha
     * \date 20/07/2016
     * \brief Number of paramaters for command
     * \details a strongly typed enum class representing number of parameters for particular command
     */
    enum class UeCommandNumberOfParameters : quint8
    {
        CMD_GET_NETWORK_SETTINGS=2,           /*!<2*/
        ACK_CMD_GET_NETWORK_SETTINGS=4,       /*!<4*/
        CMD_DATABASE_GET_PLACES=3,            /*!<3*/
        ACK_CMD_DATABASE_GET_PLACES=4,        /*!<4*/
    };   // UeCommand
}   // UePosCommProtocol

#endif // UECOMMANDS_H
