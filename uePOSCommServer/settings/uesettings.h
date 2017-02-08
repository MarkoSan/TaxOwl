#ifndef UESETTINGS_H
#define UESETTINGS_H

#include <QObject>
#include <QString>
#include <QSettings>
#include <QDateTime>
#include <QDebug>
#include <QSqlError>

#include "uesettingsdefaults.h"

class UeSettings : public QObject
{
    Q_OBJECT

private:
    QString m_ueDatabaseServerAddress;
    QString m_ueDatabaseServerPort;
    QString m_ueDatabaseName;
    QString m_ueDatabaseUsername;
    QString m_ueDatabasePassword;

    QString m_ueSettingsFile;

    QSettings* m_ueSettingsData;

    bool ueDatabaseExists();
    bool ueCreateDatabase();

public:
    explicit UeSettings(QObject *parent = 0,
                        const QString& settingsFile=QString());

    /*!
     * @brief ueDatabaseServerAddress
     * @return databaser server address
     */
    inline const QString& ueDatabaseServerAddress() const
        { return this->m_ueDatabaseServerAddress; }

    /*!
     * @brief ueDatabaseServerPort
     * @return database server port
     */
    inline const QString& ueDatabaseServerPort() const
        { return this->m_ueDatabaseServerPort; }

    /*!
     * @brief ueDatabaseName
     * @return database name
     */
    inline const QString& ueDatabaseName() const
        { return this->m_ueDatabaseName; }

    /*!
     * @brief ueDatabaseUsername
     * @return database access username
     */
    inline const QString& ueDatabaseUsername() const
        { return this->m_ueDatabaseUsername; }

    /*!
     * @brief ueDatabasePassword
     * @return database access password
     */
    inline const QString& ueDatabasePassword() const
        { return this->m_ueDatabasePassword; }

    /*!
     * @brief ueSettingsFile
     * @return string representing path to settings file
     */
    inline QString ueSettingsFile() const
        { return this->m_ueSettingsFile; }

    /*!
     * @brief ueSettingsData
     * @return settings data object
     */
    inline QSettings* ueSettingsData() const
        { return this->m_ueSettingsData; }

signals:
    //void ueSignalEventInfoAdded(const QString& eventInfo);
    void ueSignalSaveCompleted(QSettings::Status status);

public slots:
    /*!
     * @brief ueSetDatabaseServerAddress
     * @param dbServerAddress
     */
    inline void ueSetDatabaseServerAddress(const QString& dbServerAddress)
        { this->m_ueDatabaseServerAddress=dbServerAddress; }

    /*!
     * @brief ueSetDatabaseServerPort
     * @param dbServerPort
     */
    inline void ueSetDatabaseServerPort(const QString& dbServerPort)
        { this->m_ueDatabaseServerPort=dbServerPort; }

    /*!
     * @brief ueSetDatabaseName
     * @param dbName
     */
    inline void ueSetDatabaseName(const QString& dbName)
        { this->m_ueDatabaseName=dbName; }

    /*!
     * @brief ueSetDatabaseUsername
     * @param dbUsername
     */
    inline void ueSetDatabaseUsername(const QString& dbUsername)
        { this->m_ueDatabaseUsername=dbUsername; }

    /*!
     * @brief ueSetDatabasePassword
     * @param dbPassword
     */
    inline void ueSetDatabasePassword(const QString& dbPassword)
        { this->m_ueDatabasePassword=dbPassword; }

    /*!
     * @brief ueSetSettingsFile
     * @param settingsFile
     */
    inline void ueSetSettingsFile(const QString& settingsFile)
        { this->m_ueSettingsFile=settingsFile; }

    /*!
     * @brief ueSetSettingsData
     * @param settingsData
     */
    inline void ueSetSettingsData(QSettings* const settingsData)
        { this->m_ueSettingsData=settingsData; }

public slots:
    /*!
     * @brief ueSlotLoadSettings
     * @return true if success, otherwise false
     */
    bool ueSlotLoadSettings();

    /*!
     * @brief ueSlotSaveSettings
     * @param checked
     * @return true if success, otherwise false
     */
    bool ueSlotSaveSettings(bool checked);
};

#endif // UESETTINGS_H
