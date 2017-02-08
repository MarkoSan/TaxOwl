#include "uecommandswidget.h"

UeCommandsWidget::UeCommandsWidget(QWidget *parent)
    : QWidget(parent)
{
    this->setLayout(new QVBoxLayout);

    this->ueSetCmdGetDatabhasePlacesButton(new QPushButton(UePOSCommProtocol::ueCommandToString(UePosCommProtocolArch::UeCommand::CMD_DATABASE_GET_PLACES),
                                                           this));

    this->layout()->addWidget(this->ueCmdDatabasePlacesButton());
}   // constructor
