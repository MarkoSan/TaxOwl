#ifndef UECLIENT_H
#define UECLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QThreadPool>
#include <QList>
#include <QVariant>
#include <QByteArray>
#include <QMetaType>
#include <QDataStream>

#include "../uePOSCommProtocol/ueposcommprotocol.h"
#include "../ueSyntaxHighlighter/uelogentrytype.h"
#include "uetask.h"
#include "settings/uesettings.h"

/*!
 * \brief The UeClient class
 */
class UeClient : public QObject
{
    Q_OBJECT

private:
    /*!
     * \brief m_ueSocket
     */
    QTcpSocket* m_ueSocket;

    /*!
     * \brief m_ueSettings
     */
    UeSettings* m_ueSettings;

private:
    /*!
     * \brief ueSetSettings
     * \param settings
     */
    inline void ueSetSettings(UeSettings* const settings)
        { this->m_ueSettings=settings; }

    /*!
     * \brief ueSettings
     * \return pointer to object representing settings
     */
    inline UeSettings* ueSettings() const
        { return this->m_ueSettings; }

public:
    /*!
     * \brief UeClient
     * \param parent
     */
    explicit UeClient(QObject* parent=Q_NULLPTR,
                      UeSettings* const settings=Q_NULLPTR);

    /*!
     * \brief ueSetSocket
     * \param socketDescriptor
     */
    void ueSetSocket(const qintptr& socketDescriptor);

    /*!
     * \brief ueSocket
     * \return pointer to object representing tcp socket
     */
    inline QTcpSocket* ueSocket() const
        { return this->m_ueSocket; }

signals:
    /*!
     * \brief ueSignalDataArrived
     * \param executedCommand
     * \param fetchedData
     * \param parameters
     */
    void ueSignalDataArrived(const UePosCommProtocolArch::UeCommand& executedCommand,
                             const QByteArray& fetchedData,
                             const QList<QVariant>& parameters);

    /*!
     * @brief ueSignalAddEventInfoLog
     * @param messageType
     * @param message
     */
    void ueSignalAddEventInfoLog(const UeLogEntryType& messageType,
                                 const QString& message);

public slots:
    /*!
     * \brief ueSlotConnected
     */
    void ueSlotConnected();

    /*!
     * \brief ueSlotDisconnected
     */
    void ueSlotDisconnected();

    /*!
     * \brief ueSlotReadyRead
     */
    void ueSlotReadyRead();

    /*!
     * \brief ueSlotBytesWritten
     * \param bytes
     */
    void ueSlotBytesWritten(qint64 bytes);

    /*!
     * \brief ueSlotFetchData
     * \param[in] executedCommand
     * \param[in] fetchedData
     * \param[in] parameters
     */
    void ueSlotFetchData(const UePosCommProtocolArch::UeCommand& executedCommand,
                         const QByteArray& fetchedData,
                         const QList<QVariant>& parameters);

    /*!
     * \brief ueSlotReadFinished
     */
    void ueSlotReadFinished();
};

#endif // UECLIENT_H
