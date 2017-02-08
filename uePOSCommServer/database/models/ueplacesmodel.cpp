#include "ueplacesmodel.h"

UePlacesModel::UePlacesModel(QObject* parent,
                             QSqlDatabase database)
    : QSqlQueryModel(parent),
      m_ueDatabase(database)
{
}   // constructor

UePlacesModel::~UePlacesModel()
{
}   // destructor

QVariant UePlacesModel::data(const QModelIndex &item,
                             int role) const
{
    if(!(item.isValid())&&!(item.row()<0))
    {
        return QVariant();
    }   // if

    switch(role)
    {
        case ueRolePlaceId:
        {
            return this->record(item.row()).value(static_cast<int>(UeFieldIndexes::UeTablePlaces::INDEX_PLACE_ID)).toString();
        }   // case

        case ueRolePlaceName:
        {
            return this->record(item.row()).value(static_cast<int>(UeFieldIndexes::UeTablePlaces::INDEX_PLACE_NAME)).toString();
        }   // case

        case ueRolePlaceX:
        {
            return QString::number(this->record(item.row()).value(static_cast<int>(UeFieldIndexes::UeTablePlaces::INDEX_PLACE_X)).toInt());
        }   // case

        case ueRolePlaceY:
        {
            return QString::number(this->record(item.row()).value(static_cast<int>(UeFieldIndexes::UeTablePlaces::INDEX_PLACE_Y)).toInt());
        }   // case

        case ueRoleFloorName:
        {
            return this->record(item.row()).value(static_cast<int>(UeFieldIndexes::UeTablePlaces::INDEX_FLOOR_NAME)).toString();
        }   // case

        case ueRoleFloorImage:
        {
            return this->record(item.row()).value(static_cast<int>(UeFieldIndexes::UeTablePlaces::INDEX_FLOOR_IMAGE));
        }   // case

        default:
        {
            return QSqlQueryModel::data(item,
                                        role);
        }   // default
    }   // switch
}   // data

UeTypeRoles UePlacesModel::roleNames() const
{
    UeTypeRoles roles;

    const int iRolePlaceId=UePlacesModel::ueRolePlaceId;
    const int iRolePlaceName=UePlacesModel::ueRolePlaceName;
    const int iRolePlaceX=UePlacesModel::ueRolePlaceX;
    const int iRolePlaceY=UePlacesModel::ueRolePlaceY;
    const int iRoleFloorName=UePlacesModel::ueRoleFloorName;
    const int iRoleFloorImage=UePlacesModel::ueRoleFloorImage;

    roles.insert(iRolePlaceId,
                 "ueRolePlaceId");
    roles.insert(iRolePlaceName,
                 "ueRolePlaceName");
    roles.insert(iRolePlaceX,
                 "ueRolePlaceX");
    roles.insert(iRolePlaceY,
                 "ueRolePlaceY");
    roles.insert(iRoleFloorName,
                 "ueRoleFloorName");
    roles.insert(iRoleFloorImage,
                 "ueRoleFloorImage");

    return roles;
}   // roleNames

QVariantMap UePlacesModel::get(int row)
{
    QHash<int,QByteArray> names=this->roleNames();
    QHashIterator<int, QByteArray> i(names);
    QVariantMap res;

    while (i.hasNext())
    {
        i.next();
        QModelIndex idx=this->index(row,
                                    0);
        QVariant data=idx.data(i.key());
        res[i.value()]=data;
    }   // while

    return res;
}   // get

void UePlacesModel::queryChange()
{
    qDebug() << Q_FUNC_INFO
             << this->query().lastQuery();
}   // queryChange

QByteArray UePlacesModel::ueFetchData(QString& statusMessage)
{
    QByteArray result=QByteArray();

    if(!m_ueDatabase.isOpen())
    {
        if(!m_ueDatabase.open())
        {
            statusMessage=m_ueDatabase.lastError().text();

            return result;
        }
    }   // if

    this->setQuery(UeQueries::UeTablePlaces::SQL_QUERY_GET_ALL_PLACES,
                   m_ueDatabase);
    if(this->lastError().isValid())
    {
        statusMessage=this->lastError().text();

        return result;
    }
    else
    {
        QJsonDocument jsonDocument;
        QJsonArray recordsArray;
        QJsonObject recordObject;

        while(this->query().next())
        {
            for(int fieldIndex=0; fieldIndex<this->query().record().count(); fieldIndex++)
            {
                recordObject.insert(this->query().record().fieldName(fieldIndex),
                                    QJsonValue::fromVariant(this->query().value(fieldIndex)));
            }   // for

            recordsArray.push_back(recordObject);
        }   // while

        jsonDocument.setArray(recordsArray);

        statusMessage=QString::number(jsonDocument.array().size()).append(" ")
                                                                  .append(tr("records fetched from table")
                                                                  .append(" "))
                                                                  .append("PLACES");

        return jsonDocument.toBinaryData();
    }   // if
}   // ueFetchData
