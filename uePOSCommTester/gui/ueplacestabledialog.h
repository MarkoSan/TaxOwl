#ifndef UEPLACESTABLEDIALOG_H
#define UEPLACESTABLEDIALOG_H

#include <QDialog>
#include <QVBoxLayout>

#include "ueplacestableview.h"

/**
 * @brief The UePlacesTableDialog class
 */
class UePlacesTableDialog : public QDialog
{
    Q_OBJECT

private:
    /**
     * @brief m_uePlacesTableView
     */
    UePlacesTableView* m_uePlacesTableView;

protected:
    /**
     * @brief ueSetPlacesTableView
     * @param view
     */
    inline void ueSetPlacesTableView(UePlacesTableView* const view)
        { this->m_uePlacesTableView=view; }

public:
    /**
     * @brief UePlacesTableDialog
     * @param parent
     * @param f
     */
    UePlacesTableDialog(QWidget* parent=Q_NULLPTR,
                        Qt::WindowFlags f=Qt::WindowFlags());

    /**
     * @brief uePlacesTableView
     * @return pointer to objectr representing places view
     */
    inline UePlacesTableView* uePlacesTableView() const
        { return this->m_uePlacesTableView; }
};

#endif // UEPLACESTABLEDIALOG_H
