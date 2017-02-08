#ifndef UEPOSCOMMPROTOCOL_H
#define UEPOSCOMMPROTOCOL_H

#include <QByteArray>
#include <QString>
#include <QObject>
#include <QChar>
#include <QList>
#include <QVariant>

#include "uecommands.h"

/*!
 * @brief The UePOSCommProtocol class
 */
class UePOSCommProtocol : public QObject
{
    Q_OBJECT

public:
    /*!
     * \author Marko Frelih
     * \version alpha
     * \date 20/07/2016
     * \brief UePOSCommProtocol object constructor
     * \details UePOSCommProtocol constructor
     * \param[in] pointer to parent <a href="http://doc.qt.io/qt-5/qobject.html#details">QObject</a> (<a href="http://doc.qt.io/qt-5/qobject.html#details">QObject</a>*)
     * \return void
     */
    UePOSCommProtocol(QObject* parent=0);

    /*!
     * \author Marko Frelih
     * \version alpha
     * \date 20/07/2016
     * \brief returns message type
     * \details This method returns message type from incoming socket datagram
     * \param[in] reference to incoming <a href="http://doc.qt.io/qt-5/qbytearray.html#details">QByteArray</a> (const <a href="http://doc.qt.io/qt-5/qbytearray.html#details">QByteArray</a>&) datagram
     * \return message type (data, command)
     */
    static UePosCommProtocolArch::UeMessageType& ueMessageType(const QByteArray& datagram,
                                                               UePosCommProtocolArch::UeCommand& command);

    /*!
     * \author Marko Frelih
     * \version alpha
     * \date 20/07/2016
     * \brief returns encoded <a href="http://doc.qt.io/qt-5/qbytearray.html#details">QByteArray</a> (const <a href="http://doc.qt.io/qt-5/qbytearray.html#details">QByteArray</a>&) command datagram
     * \details This method returns command message composed from command and parameters
     * \param[in] command protocol command
     * \param[in] command data
     * \param[out] data size
     * \return encoded command
     */
    static const QByteArray& ueEncodeCommand(const UePosCommProtocolArch::UeCommand& command,
                                             const QList<QVariant>& data,
                                             quint32& dataSize);

    /*!
     * \author Marko Frelih
     * \version alpha
     * \date 20/07/2016
     * \brief slices incoming message to command and data
     * \details This method converts incoming message into command and data
     * \param[in] message
     * \param[in] date
     * \param[out] command
     * \return command and data
     */
    static const UePosCommProtocolArch::UeCommand& ueDecodeCommand(const QByteArray& message,
                                                                   QList<QVariant>& data);

    /*!
     * @brief ueCommandToString
     * @param command
     * @return string representing command name
     */
    static const QString& ueCommandToString(const UePosCommProtocolArch::UeCommand& command);
};

#endif // UEPOSCOMMPROTOCOL_H
