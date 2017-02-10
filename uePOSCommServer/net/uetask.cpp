#include "uetask.h"

UeTask::UeTask(const QString& databaseName,
               const QString& userName,
               const QString& password,
               const QString& hostName,
               const QString& port,
               const UePosCommProtocolArch::UeCommand& command,
               const QList<QVariant>& commandParameters)
{
    this->ueSetDatbaseName(databaseName);
    this->ueSetDatabaseUserName(userName);
    this->ueSetDatabasePassword(password);
    this->ueSetDatabaseHostName(hostName);
    this->ueSetDatabaseHostPort(port);

    this->ueSetCommand(command);
    this->ueSetCommandParameters(commandParameters);

    this->setAutoDelete(true);
}   // constructor

void UeTask::run()
{
    QString connId=QUuid::createUuid().toString();
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL",
                                              connId);
    QByteArray fetchedData=QByteArray();

    db.setDatabaseName(this->ueDatabaseName());
    db.setUserName(this->ueDatabaseUserName());
    db.setPassword(this->ueDatabasePassword());
    db.setHostName(this->ueDatabasHost());
    db.setPort(this->ueDatabaseHostPort().toInt());

    if(db.open())
    {
        QSqlQuery query(db);

        emit this->ueSignalDatabaseConnectionOk();

        switch(this->ueCommand())
        {
            case(UePosCommProtocolArch::UeCommand::CMD_INVALID_COMMAND):
            {
                break;
            }   // case

            case(UePosCommProtocolArch::UeCommand::CMD_GET_NETWORK_SETTINGS):
            {
                break;
            }   // case

            case(UePosCommProtocolArch::UeCommand::CMD_DATABASE_GET_PLACES):
            {
                if(query.exec(UeQueries::UeTablePlaces::SQL_QUERY_GET_ALL_PLACES))
                {
                    QJsonDocument jsonDocument;
                    QJsonArray jsonArray;
                    QJsonObject jsonObject;

                    while(query.next())
                    {
                        for(int fieldIndex=0; fieldIndex<query.record().count(); fieldIndex++)
                        {
                            QString fieldName=query.record().fieldName(fieldIndex);

                            if(fieldName.contains("IMAGE"))
                            {
                                jsonObject.insert(query.record().fieldName(fieldIndex),
                                                  QJsonValue(QString::fromLatin1(query.value(fieldIndex).toByteArray())));
                            }
                            else
                            {
                                jsonObject.insert(query.record().fieldName(fieldIndex),
                                                  QJsonValue::fromVariant(query.value(fieldIndex)));
                            }   // if
                        }   // for

                        jsonArray.push_back(jsonObject);
                    }   // while

                    jsonDocument.setArray(jsonArray);

                    fetchedData=jsonDocument.toBinaryData();
                }
                else
                {
                    emit this->ueSignalQueryError(query.lastError());
                }   // if

                break;
            }   // case

            case(UePosCommProtocolArch::UeCommand::ACK_CMD_GET_NETWORK_SETTINGS):
            {
                break;
            }   // case

            case(UePosCommProtocolArch::UeCommand::ACK_CMD_DATABASE_GET_PLACES):
            {
                break;
            }   // case
        }   // switch

        db.close();
    }
    else
    {
        emit this->ueSignalDatabaseConnectionError(db.lastError());
    }   // if

    db=QSqlDatabase();
    db.removeDatabase(connId);

    emit this->ueSignalTaskFinished(this->ueCommand(),
                                    fetchedData,
                                    this->ueCommandParameters());
}   // run
