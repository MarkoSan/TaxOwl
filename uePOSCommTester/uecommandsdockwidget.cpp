#include "uecommandsdockwidget.h"

UeCommandsDockWidget::UeCommandsDockWidget(const QString& title,
                                           QWidget* parent,
                                           Qt::WindowFlags flags)
    : QDockWidget(title,
                  parent,
                  flags)
{
    this->setWidget(new UeCommandsWidget(this));
}   // constructor
