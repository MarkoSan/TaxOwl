#include "uesettings.h"

/*!
 * @brief UeSettings::UeSettings
 * @param parent
 */
UeSettings::UeSettings(QObject *parent,
                       const QString& settingsFile)
    : QObject(parent),
      m_ueSettingsFile(settingsFile)
{
    QString logText=QString();

    this->ueSetDatabaseServerAddress(QString());
    this->ueSetDatabaseServerPort(QString());
    this->ueSetDatabaseName(QString());
    this->ueSetDatabaseUsername(QString());
    this->ueSetDatabasePassword(QString());
    this->ueSetSettingsData(new QSettings(this->ueSettingsFile(),
                                          QSettings::IniFormat,
                                          this));
/*
    connect(this,
            SIGNAL(ueSignalEventInfoAdded(QString)),
            parent,
            SLOT(ueSlotEventInfoAdded(QString)));

    logText=tr("[INFO]").append(" ")
                        .append(QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss:zzz"))
                        .append(" ")
                        .append(tr("Config file status ")
                        .append(this->ueSettingsData()->fileName())
                        .append(": ")
                        .append(QString::number(this->ueSettingsData()->status())));

    emit this->ueSignalEventInfoAdded(logText);
*/
}   // constructor

/*!
 * @brief UeSettings::ueDatabaseExists
 * @return true if database exists, otherwise false
 */
bool UeSettings::ueDatabaseExists()
{
    bool result=false;

    return result;
}   // ueDatabaseExists

/*!
 * @brief UeSettings::ueCreateDatabase
 * @return true if database successfully created, otherwise false
 */
bool UeSettings::ueCreateDatabase()
{
    bool result=false;

    return result;
}   // ueCreateDatabase

/*!
 * @brief UeSettings::ueLoadSettings
 * @return true if success, otherwise false
 */
bool UeSettings::ueSlotLoadSettings()
{
    bool result=false;

    this->ueSetDatabaseServerAddress(this->ueSettingsData()->value(UeSettingsDefaults::UeSettings::SETTING_DATABASE_SERVER_ADDRESS).toString());
    this->ueSetDatabaseServerPort(this->ueSettingsData()->value(UeSettingsDefaults::UeSettings::SETTING_DATABASE_SERVER_PORT).toString());
    this->ueSetDatabaseName(this->ueSettingsData()->value(UeSettingsDefaults::UeSettings::SETTING_DATABASE_NAME).toString());
    this->ueSetDatabaseUsername(this->ueSettingsData()->value(UeSettingsDefaults::UeSettings::SETTING_DATABASE_USERNAME).toString());
    this->ueSetDatabasePassword(this->ueSettingsData()->value(UeSettingsDefaults::UeSettings::SETTING_DATABASE_PASSWORD).toString());

    if(!this->ueDatabaseServerAddress().isEmpty()&&!this->ueDatabaseServerPort().isEmpty()&&
       !this->ueDatabaseName().isEmpty()&&!this->ueDatabaseUsername().isEmpty()&&!this->ueDatabasePassword().isEmpty())
    {
        result=true;
    }   // if

    return result;
}   // ueLoadSettings

bool UeSettings::ueSlotSaveSettings(bool checked)
{
    Q_UNUSED(checked);

    QString logText=QString();
    bool result=false;

    if(!this->ueDatabaseServerAddress().isEmpty()&&!this->ueDatabaseServerPort().isEmpty()&&
       !this->ueDatabaseName().isEmpty()&&!this->ueDatabaseUsername().isEmpty()&&
       !this->ueDatabasePassword().isEmpty())
    {
        this->ueSettingsData()->setValue(UeSettingsDefaults::UeSettings::SETTING_DATABASE_SERVER_ADDRESS,
                                                       this->ueDatabaseServerAddress());
        this->ueSettingsData()->setValue(UeSettingsDefaults::UeSettings::SETTING_DATABASE_SERVER_PORT,
                                                       this->ueDatabaseServerPort());
        this->ueSettingsData()->setValue(UeSettingsDefaults::UeSettings::SETTING_DATABASE_NAME,
                                                       this->ueDatabaseName());
        this->ueSettingsData()->setValue(UeSettingsDefaults::UeSettings::SETTING_DATABASE_USERNAME,
                                                       this->ueDatabaseUsername());
        this->ueSettingsData()->setValue(UeSettingsDefaults::UeSettings::SETTING_DATABASE_PASSWORD,
                                                       this->ueDatabasePassword());

        this->ueSettingsData()->sync();
        if(this->ueSettingsData()->status()==QSettings::NoError)
        {

//        logText=tr("[INFO]").append(" ")
//                            .append(QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss:zzz"))
//                            .append(" ")
//                            .append(tr("Config file status ")
//                            .append(this->ueSettingsData()->fileName())
//                            .append(": ")
//                            .append(QString::number(this->ueSettingsData()->status())));

//        emit this->ueSignalEventInfoAdded(logText);

            result=true;
        }   // if
    }   // if

    emit this->ueSignalSaveCompleted(this->ueSettingsData()->status());

    return result;
}   // ueSlotSaveSettings
