#ifndef UEJSONPLACESTABLEMODEL_H
#define UEJSONPLACESTABLEMODEL_H

#include <QAbstractTableModel>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QVariant>
#include <QVariantMap>
#include <QVariantList>
#include <QPixmap>
#include <QSize>
#include <QImage>
#include <QBuffer>

#include <QDebug>

/*!
 * \brief The UeJsonPlacesTableModel class
 */
class UeJsonPlacesTableModel : public QAbstractTableModel
{
private:
    /*!
     * @brief m_ueJsonData
     */
    QJsonDocument m_ueJsonData;

public:
    /*!
     * @brief ueSetJsonData
     * @param jsonData
     */
    void ueSetJsonData(const QJsonDocument& jsonData);

public:
    /*!
     * @brief UeJsonPlacesTableModel
     * @param parent
     */
    UeJsonPlacesTableModel(QObject* parent=Q_NULLPTR);

    /*!
     * @brief ueJsonData
     * @return pointer to object representing JSON document
     */
    const QJsonDocument& ueJsonData()
        { return this->m_ueJsonData; }

    /*!
     * @brief rowCount
     * @param parent
     * @return number of rows
     */
    int rowCount(const QModelIndex& parent=QModelIndex()) const;

    /*!
     * @brief columnCount
     * @param parent
     * @return number of columns
     */
    int columnCount(const QModelIndex& parent=QModelIndex()) const;

    /*!
     * @brief data
     * @param index
     * @param role
     * @return data
     */
    QVariant data(const QModelIndex& index,
                  int role=Qt::DisplayRole) const;

    /*!
     * @brief headerData
     * @param section
     * @param orientation
     * @param role
     * @return header data
     */
    QVariant headerData(int section,
                        Qt::Orientation orientation=Qt::Horizontal,
                        int role=Qt::DisplayRole) const;

    /*!
     * @brief flags
     * @param index
     * @return flags for index's cell
     */
    Qt::ItemFlags flags(const QModelIndex& index) const;

    /*!
     * @brief setData
     * @param index
     * @param value
     * @param role
     * @return true if succesfull, otherwise false
     */
    bool setData(const QModelIndex& index,
                 const QVariant& value,
                 int role=Qt::EditRole);

    /*!
     * @brief insertRows
     * @param row
     * @param count
     * @param parent
     * @return true if succesfull, otherwise false
     */
    bool insertRows(int row,
                    int count,
                    const QModelIndex& parent=QModelIndex());

    /*!
     * @brief removeRows
     * @param row
     * @param count
     * @param parent
     * @return true if succesfull, otherwise false
     */
    bool removeRows(int row,
                    int count,
                    const QModelIndex& parent=QModelIndex());

    /*!
     * \brief ueAddPlaceRecord
     * \param placeId
     * \param placeName
     * \param placeX
     * \param placeY
     * \param floorName
     * \param floorImage
     */
    void ueAddPlaceRecord(const QString& placeId,
                          const QString& placeName,
                          const QString& placeX,
                          const QString& placeY,
                          const QString& floorName,
                          const QPixmap& floorImage);
};

#endif // UEJSONPLACESTABLEMODEL_H
