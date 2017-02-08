#ifndef UEPLACESMODEL_H
#define UEPLACESMODEL_H

#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QVariant>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QString>
#include <QSqlError>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QByteArray>
#include <QSqlDriver>

#include <QDebug>

#include "uetypes.h"
#include "uefieldindexes.h"
#include "uequeries.h"

/*!
 * \brief The UePlacesModel class
 */
class UePlacesModel : public QSqlQueryModel
{
    Q_OBJECT

private:
    /*!
     * @brief m_ueDatabase
     */
    QSqlDatabase m_ueDatabase;

public:
    /*!
     * @brief UePlacesModel
     * @param parent
     */
    UePlacesModel(QObject* parent=0,
                  QSqlDatabase database=QSqlDatabase());

    /*!
     * @brief ~UePlacesModel
     */
    ~UePlacesModel();

    /*!
     * @brief data
     * @param index
     * @param role
     * @return data for role
     */
    QVariant data(const QModelIndex &item,
                  int role=Qt::DisplayRole) const Q_DECL_OVERRIDE;

    /*!
     * @brief roleNames
     * @return roles
     */
    UeTypeRoles roleNames() const Q_DECL_OVERRIDE;

    /*!
     * @brief get
     * @return data for row
     */
    Q_INVOKABLE QVariantMap get(int row);

    /*!
     * @brief queryChange
     */
    void queryChange() Q_DECL_OVERRIDE;

    /*!
     * @brief ueFetchData
     * @param statusMessage
     * @return data in json format, empty if error
     */
    QByteArray ueFetchData(QString& statusMessage);

public:
    /*!
     * @brief ueRoleId
     */
    static const int ueRolePlaceId=Qt::UserRole+1;

    /*!
     * @brief ueRoleName
     */
    static const int ueRolePlaceName=Qt::UserRole+2;

    /*!
     * @brief ueRoleX
     */
    static const int ueRolePlaceX=Qt::UserRole+3;

    /*!
     * @brief ueRoleY
     */
    static const int ueRolePlaceY=Qt::UserRole+4;

    /*!
     * @brief ueRoleFloor
     */
    static const int ueRoleFloorName=Qt::UserRole+5;

    /*!
     * \brief ueRoleFloorImage
     */
    static const int ueRoleFloorImage=Qt::UserRole+6;
};

#endif // UEPLACESMODEL_H
