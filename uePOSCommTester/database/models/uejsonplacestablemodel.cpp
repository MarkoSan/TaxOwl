#include "uejsonplacestablemodel.h"

UeJsonPlacesTableModel::UeJsonPlacesTableModel(QObject* parent)
    : QAbstractTableModel(parent)
{
}   // constructor

int UeJsonPlacesTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)

    return this->m_ueJsonData.isArray()?this->m_ueJsonData.array().size():this->m_ueJsonData.isObject()?this->m_ueJsonData.object().size():0;
}   // rowCount

void UeJsonPlacesTableModel::ueSetJsonData(const QJsonDocument& jsonData)
{
    QJsonArray dataArray=jsonData.array();
    QJsonArray::iterator dataIterator;
    int dataIteratorCounter=0;

    this->beginResetModel();

    this->m_ueJsonData=jsonData;

    foreach(const QJsonValue& record,
            dataArray)
    {
        QByteArray floorImageByteArray=record.toObject().value(record.toObject().keys().at(0)).toVariant().toByteArray();

        QPixmap floorImage;

        if(!floorImage.loadFromData(floorImageByteArray))
        {
            floorImage=QPixmap::fromImage(QImage(":/ueIcons/icons/ueNoPlaceImageIcon.png"));
        }   // if

        this->ueAddPlaceRecord(record.toObject().value(record.toObject().keys().at(2)).toString(),
                               record.toObject().value(record.toObject().keys().at(3)).toString(),
                               record.toObject().value(record.toObject().keys().at(4)).toString(),
                               record.toObject().value(record.toObject().keys().at(5)).toString(),
                               record.toObject().value(record.toObject().keys().at(1)).toString(),
                               floorImage);

        dataIteratorCounter++;
    }   // foreach

    emit dataChanged(QModelIndex(),
                     QModelIndex());

    this->endResetModel();
}   // ueSetJsonData

int UeJsonPlacesTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)

    return this->m_ueJsonData.isArray()?this->m_ueJsonData.array().at(0).toObject().keys().size():this->m_ueJsonData.isObject()?this->m_ueJsonData.object().keys().size():0;
}   // columnCount

QVariant UeJsonPlacesTableModel::data(const QModelIndex& index,
                                      int role) const
{
    QVariant result=QVariant();
    int row=index.row();
    int column=index.column();

    switch(role)
    {
        case Qt::DisplayRole:
        {
            if(row<0||
               row>=this->rowCount()||
               column<0||
               column>=this->columnCount())
            {
                return result;
            }
            else
            {
                if(this->m_ueJsonData.isArray())
                {
                    if(this->m_ueJsonData.array().size()<=0)
                    {
                        return result;
                    }
                    else
                    {
                        result=this->m_ueJsonData.array().at(row).toObject().value(this->m_ueJsonData.array().at(row).toObject().keys().at(column)).toString();
                    }   // if
                }
                else
                {
                    // it is not array, it is object

                    if(this->m_ueJsonData.object().size()<=0)
                    {
                        return result;
                    }
                    else
                    {
                        result=this->m_ueJsonData.object().value(this->m_ueJsonData.array().at(row).toObject().keys().at(column)).toString();
                    }   // if
                }   // if
            }   // if

            break;
        }   // case

        case Qt::DecorationRole:
        {
            //BUG due to fields sequence incosistency resulted in SQL->JSon serialization, SQL statement does not guarantee fields order anymore and therefore FLOOR_IMAGE field has index 0
            if(column==0)
            {
                if(this->m_ueJsonData.isArray())
                {
                    if(this->m_ueJsonData.array().size()<=0)
                    {
                        return result;
                    }
                    else
                    {
                        result=QPixmap::fromImage(QImage::fromData(this->m_ueJsonData.array().at(row).toObject().value(this->m_ueJsonData.array().at(row).toObject().keys().at(column)).toVariant().toByteArray()));
                    }   // if
                }
                else
                {
                    // it is not array, it is object

                    if(this->m_ueJsonData.object().size()<=0)
                    {
                        return result;
                    }
                    else
                    {
                        result=QPixmap::fromImage(QImage::fromData(this->m_ueJsonData.array().at(row).toObject().value(this->m_ueJsonData.array().at(row).toObject().keys().at(column)).toVariant().toByteArray()));
                    }   // if
                }   // if
            }
            else
            {
                if(this->m_ueJsonData.isArray())
                {
                    if(this->m_ueJsonData.array().size()<=0)
                    {
                        return result;
                    }
                    else
                    {
                        result=this->m_ueJsonData.array().at(row).toObject().value(this->m_ueJsonData.array().at(row).toObject().keys().at(column)).toString();
                    }   // if
                }
                else
                {
                    // it is not array, it is object

                    if(this->m_ueJsonData.object().size()<=0)
                    {
                        return result;
                    }
                    else
                    {
                        result=this->m_ueJsonData.object().value(this->m_ueJsonData.array().at(row).toObject().keys().at(column)).toString();
                    }   // if
                }   // if
            }   // if

            break;
        }   // case

        case Qt::SizeHintRole:
        {
            result=QSize(256,
                         256);//result.toByteArray().size();

            break;
        }   // case
    }   // switch

    return result;
}   // data

QVariant UeJsonPlacesTableModel::headerData(int section,
                                            Qt::Orientation orientation,
                                            int role) const
{
    QVariant result=QVariant();

    if(role!=Qt::DisplayRole||
       section<0||
       section>=this->columnCount())
    {
        return result;
    }   // if

    switch(orientation)
    {
        case Qt::Horizontal:
        {
            //BUG fields sequence is not same as instructed from SQL statement
            result=this->m_ueJsonData.array().at(0).toObject().keys().at(section);

            break;
        }   // case

        case Qt::Vertical:
        {
            return QAbstractTableModel::headerData(section,
                                                   orientation,
                                                   role);
        }   // case
    }   // switch

    return result;
}   // headerData

Qt::ItemFlags UeJsonPlacesTableModel::flags(const QModelIndex& index) const
{
    return index.column()==0?QAbstractTableModel::flags(index)^Qt::ItemIsEditable:QAbstractTableModel::flags(index);
}   // flags

bool UeJsonPlacesTableModel::setData(const QModelIndex& index,
                                     const QVariant& value,
                                     int role)
{
    bool result=false;
    int row=index.row();
    int column=index.column();
    QVariantList dataList=QVariantList();
    QVariantMap dataVariantMap=QVariantMap();
    QVariantMap::const_iterator dataIterator;
    int dataIndex=0;
    QString keyName=QString();
    QString dataValue=QString();
    QVariantMap changedData=QVariantMap();

    switch(role)
    {
        case Qt::DisplayRole:
        {
            if(row<0||
               row>=this->rowCount()||
               column<0||
               column>=this->columnCount())
            {
                return result;
            }
            else
            {
                dataList=this->m_ueJsonData.toVariant().toList();
                dataVariantMap=this->m_ueJsonData.toVariant().toList().at(index.row()).toMap();
                dataIterator=dataVariantMap.constBegin();

                while(dataIterator!=dataVariantMap.constEnd())
                {
                    if(dataIndex==index.column())
                    {
                        keyName=dataVariantMap.keys().at(dataIndex);

                        dataIterator++;
                        dataIndex++;
                    }   // if
                }   // while

//                qDebug() << Q_FUNC_INFO
//                         << value;

                changedData.insert(keyName,
                                   value.toString());

                result=true;
            }   // if

            break;
        }   // case

        case Qt::EditRole:
        {
            if(row<0||
               row>=this->rowCount()||
               column<0||
               column>=this->columnCount())
            {
                return result;
            }
            else
            {
                dataList=this->m_ueJsonData.toVariant().toList();
                dataVariantMap=this->m_ueJsonData.toVariant().toList().at(index.row()).toMap();
                dataIterator=dataVariantMap.constBegin();

                while(dataIterator!=dataVariantMap.constEnd())
                {
                    if(dataIndex==index.column())
                    {
                        keyName=dataVariantMap.keys().at(dataIndex);

                        dataIterator++;
                        dataIndex++;
                    }   // if
                }   // while

//                qDebug() << Q_FUNC_INFO
//                         << value;

                changedData.insert(keyName,
                                   value.toString());

                result=true;

                break;
            }   // if
        }   // case

        case Qt::DecorationRole:
        {
            if(row<0||
               row>=this->rowCount()||
               column<0||
               column>=this->columnCount())
            {
                return result;
            }
            else
            {
                if(column==0)
                {
                    dataList=this->m_ueJsonData.toVariant().toList();
                    dataVariantMap=this->m_ueJsonData.toVariant().toList().at(index.row()).toMap();
                    dataIterator=dataVariantMap.constBegin();

                    while(dataIterator!=dataVariantMap.constEnd())
                    {
                        if(dataIndex==index.column())
                        {
                            keyName=dataVariantMap.keys().at(dataIndex);

                            dataIterator++;
                            dataIndex++;
                        }
                        else
                        {
                            break;
                        }   // if
                    }   // while

                    changedData.insert(keyName,
                                       value);

                    result=true;
                }
                else
                {
                    return result;
                }   // if
            }   // if

            break;
        }   // case
    }   // switch

    dataList.replace(index.row(),
                     changedData);

    this->m_ueJsonData=QJsonDocument::fromVariant(dataList);

    emit dataChanged(index,
                     index);

    return result;
}   // setData

bool UeJsonPlacesTableModel::insertRows(int row,
                                        int count,
                                        const QModelIndex& parent)
{
    this->beginInsertRows(parent,
                          row,
                          row+count-1);

    for(int index=row; index<row+count; ++index)
    {
        this->m_ueJsonData.toVariant().toList().insert(row,
                                                       this->m_ueJsonData.toVariant());
    }   // for

    this->endInsertRows();

    return true;
}   // insertRows

bool UeJsonPlacesTableModel::removeRows(int row,
                                        int count,
                                        const QModelIndex& parent)
{
    this->beginRemoveRows(parent,
                          row,
                          row+count-1);

    for(int index=row; index<row+count; ++index)
    {
        this->m_ueJsonData.toVariant().toList().removeAt(index);
    }   // for

    this->endRemoveRows();

    return true;
}   // removeRows

void UeJsonPlacesTableModel::ueAddPlaceRecord(const QString& placeId,
                                              const QString& placeName,
                                              const QString& placeX,
                                              const QString& placeY,
                                              const QString& floorName,
                                              const QPixmap& floorImage)
{
    QModelIndex index;

    this->insertRows(0,
                     1,
                     QModelIndex());

    index=this->index(0,
                      0,
                      QModelIndex());
    this->setData(index,
                  floorImage,
                  Qt::DecorationRole);

    index=this->index(0,
                      1,
                      QModelIndex());
    this->setData(index,
                  floorName,
                  Qt::EditRole);

    index=this->index(0,
                      2,
                      QModelIndex());
    this->setData(index,
                  placeId,
                  Qt::EditRole);

    index=this->index(0,
                      3,
                      QModelIndex());
    this->setData(index,
                  placeName,
                  Qt::EditRole);

    index=this->index(0,
                      4,
                      QModelIndex());
    this->setData(index,
                  placeX,
                  Qt::EditRole);

    index=this->index(0,
                      5,
                      QModelIndex());
    this->setData(index,
                  placeY,
                  Qt::EditRole);
}   // ueAddPlaceRecord
