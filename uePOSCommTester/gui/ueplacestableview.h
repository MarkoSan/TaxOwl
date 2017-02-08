#ifndef UEPLACESTABLEVIEW_H
#define UEPLACESTABLEVIEW_H

#include <QTableView>
#include <QHeaderView>

#include "../database/models/uejsonplacestablemodel.h"

/*!
 * \brief The UePlacesTableView class
 */
class UePlacesTableView : public QTableView
{
    Q_OBJECT

private:
    /**
     * @brief m_ueTablePlacesModel
     */
    UeJsonPlacesTableModel* m_ueTablePlacesModel;

public:
    /**
     * @brief UePlacesTableView
     * @param parent
     */
    UePlacesTableView(QWidget* parent=Q_NULLPTR);
};

#endif // UEPLACESTABLEVIEW_H
