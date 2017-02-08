#ifndef UESETTINGSDEFAULTS_H
#define UESETTINGSDEFAULTS_H

#include <QString>

namespace UeSettingsDefaults
{
    namespace UeApplication
    {
        static const QString APP_NAME="uePOSCommServer";
    }   // UeApplication

    namespace UeCompany
    {
        static const QString COMPANY_NAME="Mikroelektronika Marko Frelih s.p.";
        static const QString COMPANY_ADDRESS="Topniška 35d";
        static const QString COMPANY_ZIPCODE="1000";
        static const QString COMPANY_CITY="Ljubljana";
        static const QString COMPANY_STATE="Republika Slovenija";
        static const QString COMPANY_IDENTIFICATION_NUMBER="6780610000";
        static const QString COMPANY_TAX_NUMBER="88763340";
        static const QString COMPANY_DOMAIN="mikroelektronika.si";
    }   // UeCompany

    namespace UeSettings
    {
        static const QString SETTINGS_FILE_NAME=UeSettingsDefaults::UeApplication::APP_NAME+".conf";

        static const QString SETTING_COMM_SERVER_WELCOME_PORT="commserverwelcomeport";
        static const QString SETTING_COMM_SERVER_PORT="commserverport";
        static const QString SETTING_COMM_SERVER_NETWORK_INTERFACE_NAME="commserverifacename";
        static const QString SETTING_COMM_SERVER_NETWORK_INTERFACE_ADDRESS="commserverifaceaddress";
        static const QString SETTING_COMM_SERVER_NETWORK_INFRASTRUCTURE_CHANGE_SOCKET_PORT="commservernetworkinfrastructurechangesocketport";

        static const QString SETTING_DATABASE_SERVER_ADDRESS="address";
        static const QString SETTING_DATABASE_SERVER_PORT="dbserverport";
        static const QString SETTING_DATABASE_NAME="dbname";
        static const QString SETTING_DATABASE_USERNAME="dbusername";
        static const QString SETTING_DATABASE_PASSWORD="dbpassword";
    }   // UeSettings

    namespace UeDatabase
    {
        static const QString DATABASE_DRIVER="QMYSQL";
        static const QString DATABASE_CONNECTION_NAME=UeSettingsDefaults::UeApplication::APP_NAME;
    }   // UeDatabase
}   // UeSettingsDefaults

#endif // UESETTINGSDEFAULTS_H
