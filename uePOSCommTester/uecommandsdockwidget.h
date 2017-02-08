#ifndef UECOMMANDSDOCKWIDGET_H
#define UECOMMANDSDOCKWIDGET_H

#include <QDockWidget>

#include "uecommandswidget.h"

/*!
 * \brief The UeCommandsDockWidget class
 */
class UeCommandsDockWidget : public QDockWidget
{
    Q_OBJECT

public:
    /**
     * @brief UeCommandsDockWidget
     * @param title
     * @param parent
     * @param flags
     */
    UeCommandsDockWidget(const QString& title,
                         QWidget *parent=Q_NULLPTR,
                         Qt::WindowFlags flags=Qt::WindowFlags());
};

#endif // UECOMMANDSDOCKWIDGET_H
