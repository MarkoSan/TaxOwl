#ifndef UETASK_H
#define UETASK_H

#include <QObject>
#include <QRunnable>
#include <QSqlDatabase>
#include <QSqlError>
#include <QUuid>
#include <QString>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>
#include <QByteArray>
#include <QDebug>
#include <QList>
#include <QVariant>

#include "../../uePOSCommProtocol/uecommands.h"
#include "database/models/uefieldindexes.h"
#include "database/models/uequeries.h"

/*!
 * \brief The UeTask class
 */
class UeTask : public QObject,
               public QRunnable
{
    Q_OBJECT

private:
    /*!
     * \brief m_ueDatabaseName
     */
    QString m_ueDatabaseName;

    /*!
     * \brief m_ueUserName
     */
    QString m_ueUserName;

    /*!
     * \brief m_uePassword
     */
    QString m_uePassword;

    /*!
     * \brief m_ueHostName
     */
    QString m_ueHostName;

    /*!
     * \brief m_uePort
     */
    QString m_uePort;

    /*!
     * \brief m_ueCommand
     */
    UePosCommProtocolArch::UeCommand m_ueCommand;

    /*!
     * \brief m_ueCommandParameters
     */
    QList<QVariant> m_ueCommandParameters;

    /*!
     * @brief ueDatabaseName
     * @return database name
     */
    inline const QString& ueDatabaseName() const
        { return this->m_ueDatabaseName; }

    /*!
     * @brief ueDatabaseUserName
     * @return database user name
     */
    inline const QString& ueDatabaseUserName() const
        { return this->m_ueUserName; }

    /*!
     * @brief ueDatabasePassword
     * @return database password
     */
    inline const QString& ueDatabasePassword() const
        { return this->m_uePassword; }

    /*!
     * @brief ueDatabasHost
     * @return database host name
     */
    inline const QString& ueDatabasHost() const
        { return this->m_ueHostName; }

    /*!
     * @brief uePort
     * @return database host port
     */
    inline const QString& ueDatabaseHostPort() const
        { return this->m_uePort; }

    /*!
     * \brief ueCommand
     * \return task command
     */
    inline UePosCommProtocolArch::UeCommand& ueCommand()
        { return this->m_ueCommand; }

    /*!
     * \brief ueCommandParameters
     * \return reference to a list of command parameters
     */
    inline const QList<QVariant>& ueCommandParameters()
        { return this->m_ueCommandParameters; }

    /*!
     * @brief ueSetDatbaseName
     * @param name
     */
    inline void ueSetDatbaseName(const QString& name)
        { this->m_ueDatabaseName=name; }

    /*!
     * @brief ueSetDatabaseUserName
     * @param userName
     */
    inline void ueSetDatabaseUserName(const QString& userName)
        { this->m_ueUserName=userName; }

    /*!
     * @brief ueSetDatabasePassword
     * @param password
     */
    inline void ueSetDatabasePassword(const QString& password)
        { this->m_uePassword=password; }

    /*!
     * @brief ueSetDatabaseHostName
     * @param hostName
     */
    inline void ueSetDatabaseHostName(const QString& hostName)
        { this->m_ueHostName=hostName; }

    /*!
     * @brief ueSetDatabaseHostPort
     * @param port
     */
    inline void ueSetDatabaseHostPort(const QString& port)
        { this->m_uePort=port; }

    /*!
     * \brief ueSetCommand
     * \param command
     */
    inline void ueSetCommand(const UePosCommProtocolArch::UeCommand& command)
        { this->m_ueCommand=command; }

    /*!
     * \brief ueSetCommandParameters
     * \param commandParameters
     */
    inline void ueSetCommandParameters(const QList<QVariant>& commandParameters)
        { this->m_ueCommandParameters=commandParameters; }

public:
    /*!
     * \brief UeTask
     * \param databaseName
     * \param userName
     * \param password
     * \param hostName
     * \param port
     * \param command
     * \param commandParameters
     */
    explicit UeTask(const QString& databaseName,
                    const QString& userName,
                    const QString& password,
                    const QString& hostName,
                    const QString& port,
                    const UePosCommProtocolArch::UeCommand& command,
                    const QList<QVariant>& commandParameters);

protected:
    /*!
     * @brief run
     */
    void run();

signals:
    /*!
     * \brief ueSignalTaskFinished
     * \param executedCommand
     * \param fetchedData
     * \param commandParameters
     */
    void ueSignalTaskFinished(const UePosCommProtocolArch::UeCommand& executedCommand,
                              const QByteArray& fetchedData,
                              const QList<QVariant>& commandParameters);

    /*!
     * @brief ueSignalDatabaseConnectionOk
     */
    void ueSignalDatabaseConnectionOk();

    /*!
     * @brief ueSignalDatabaseConnectionError
     * @param error
     */
    void ueSignalDatabaseConnectionError(const QSqlError& error);

    /*!
     * \brief ueSignalQueryError
     * \param error
     */
    void ueSignalQueryError(const QSqlError& error);
};

#endif // UETASK_H
