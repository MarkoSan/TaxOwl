#ifndef UECONNECTEDCLIENTRECORD_H
#define UECONNECTEDCLIENTRECORD_H

#include <QtGlobal>
#include <QObject>
#include <QHostAddress>
#include <QString>

class UeConnectedClientRecord : public QObject
{
    Q_OBJECT

private:
    /*!
     * @brief m_ueClientName
     */
    QString m_ueClientName;

    /*!
     * @brief m_ueClientAddress
     */
    QHostAddress m_ueClientAddress;

    /*!
     * @brief m_ueClientPort
     */
    QString m_ueClientPort;

    /*!
     * @brief m_ueClientOS
     */
    QString m_ueClientOS;

public:
    /*!
     * @brief UeConnectedClientRecord
     * @param parent
     */
    explicit UeConnectedClientRecord(const QString& clientName=QString(),
                                     const QHostAddress& clientAddress=QHostAddress(),
                                     const QString& clientPort=QString(),
                                     const QString& clientOS=QString());

    /*!
     * @brief ueSetClientName
     * @param name
     */
    inline void ueSetClientName(const QString& name)
        { this->m_ueClientName=name; }

    /*!
     * @brief ueSetClientAddress
     * @param address
     */
    inline void ueSetClientAddress(const QHostAddress& address)
        { this->m_ueClientAddress=address; }

    /*!
     * @brief ueSetClientPort
     * @param port
     */
    inline void ueSetClientPort(const QString& port)
        { this->m_ueClientPort=port; }

    /*!
     * @brief ueSetClientOS
     * @param clientOS
     */
    inline void ueSetClientOS(const QString& clientOS)
        { this->m_ueClientOS=clientOS; }

    /*!
     * @brief ueClientName
     * @return client name
     */
    inline const QString& ueClientName() const
        { return this->m_ueClientName; }

    /*!
     * @brief ueClientAddress
     * @return client address
     */
    inline const QHostAddress& ueClientAddress() const
        { return this->m_ueClientAddress; }

    /*!
     * @brief ueClientPort
     * @return client port
     */
    inline const QString& ueClientPort() const
        { return this->m_ueClientPort; }

    /*!
     * @brief ueClientOS
     * @return client OS
     */
    inline const QString& ueClientOS() const
        { return this->m_ueClientOS; }

public:
    /*!
     * @brief INDEX_CLIENT_NAME
     */
    static const int INDEX_CLIENT_NAME=0;

    /*!
     * @brief INDEX_CLIENT_ADDRESS
     */
    static const int INDEX_CLIENT_ADDRESS=1;

    /*!
     * @brief INDEX_CLIENT_PORT
     */
    static const int INDEX_CLIENT_PORT=2;


    /*!
      * @brief INDEX_CLIENT_OS
      */
    static const int INDEX_CLIENT_OS=3;


    /*!
     * @brief NUMBER_OF_FILEDS
     */
    static const int NUMBER_OF_FILEDS=4;
};

#endif // UECONNECTEDCLIENTRECORD_H
