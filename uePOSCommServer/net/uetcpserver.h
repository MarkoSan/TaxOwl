#ifndef UETCPSERVER_H
#define UETCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QDateTime>

#include "ueclient.h"
#include "../ueSyntaxHighlighter/uelogentrytype.h"
#include "../ueSyntaxHighlighter/uelogwindow.h"
#include "settings/uesettingsdefaults.h""

/*!
 * @brief The UeTcpServer class
 */
class UeTcpServer : public QTcpServer
{
    Q_OBJECT

private:
    UeSettings* m_ueSettings;

protected:
    /*!
     * \brief incomingConnection
     * \param socketDescriptor
     */
    void incomingConnection(qintptr socketDescriptor);

public:
    /*!
     * @brief UeTcpServer
     * @param parent
     */
    explicit UeTcpServer(QObject* parent=Q_NULLPTR,
                         UeSettings* const settings=Q_NULLPTR);

    /*!
     * @brief ~UeTcpServer
     */
    ~UeTcpServer();

    /*!
     * @brief ueStart
     * @param port
     * @return true if success, otherwise false
     */
    bool ueStart(const quint16& port);

    /*!
     * \brief ueRestart
     * \param address
     * \param port
     */
    void ueRestart(const QHostAddress& address,
                   const quint16& port);

    /*!
     * \brief ueServerIPv4
     * \return server's current IPv4 address
     */
    const QHostAddress& ueServerIPv4() const;

    /*!
     * @brief ueServerPort
     * @return server's current port
     */
    inline quint16 ueServerPort() const
        { return this->serverPort(); }

    /*!
     * \brief ueSettings
     * \return pointer to object representing settings from configuration file
     */
    inline UeSettings* ueSettings() const
        { return this->m_ueSettings; }

signals:
    /*!
     * \brief ueSignalEmitLogEvent
     * \param messageType
     * \param message
     */
    void ueSignalEmitLogEvent(const UeLogEntryType& messageType,
                              const QString& message);

    /*!
     * \brief ueSignalDataArrived
     * \param executedCommand
     * \param fetchedData
     * \param parameters
     */
    void ueSignalDataArrived(const UePosCommProtocolArch::UeCommand& executedCommand,
                             const QByteArray& fetchedData,
                             const QList<QVariant>& parameters);

public slots:
    /*!
     * \brief ueSlotDataArrived
     * \param executedCommand
     * \param fetchedData
     * \param parameters
     */
    void ueSlotDataArrived(const UePosCommProtocolArch::UeCommand& executedCommand,
                           const QByteArray& fetchedData,
                           const QList<QVariant>& parameters);

    /*!
     * \brief ueSlotAddEventInfoLog
     * \param messageType
     * \param message
     */
    void ueSlotAddEventInfoLog(const UeLogEntryType& messageType,
                               const QString& message);
};

#endif // UETCPSERVER_H
