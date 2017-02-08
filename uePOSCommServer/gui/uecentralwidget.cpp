#include "uecentralwidget.h"

UeCentralWidget::UeCentralWidget(QWidget *parent)
    : QWidget(parent)
{
    this->setLayout(new QVBoxLayout(this));
    this->ueSetButtonsLayout(new QHBoxLayout());

    this->ueSetLogWindow(new UeLogWindow(this));

    this->ueSetButtonClear(new QPushButton(tr("Clear"),
                                           this));
    this->ueSetButtonExportTo(new QPushButton(tr("Export to"),
                                              this));
    this->ueSetButtonSearch(new QPushButton(tr("Search"),
                                            this));
    this->ueSetCmdSendNetworkSettingsButton(new QPushButton(UePOSCommProtocol::ueCommandToString(UePosCommProtocolArch::UeCommand::CMD_GET_NETWORK_SETTINGS),
                                                        this));
    this->ueSetButtonQuit(new QPushButton(tr("Quit"),
                                          this));

    this->ueSetInfoLayout(new QHBoxLayout());

    dynamic_cast<QHBoxLayout*>(this->ueButtonsLayout())->addWidget(this->ueButtonClear());
    dynamic_cast<QHBoxLayout*>(this->ueButtonsLayout())->addWidget(this->ueButtonExportTo());
    dynamic_cast<QHBoxLayout*>(this->ueButtonsLayout())->addWidget(this->ueButtonSearch());
    dynamic_cast<QHBoxLayout*>(this->ueButtonsLayout())->addWidget(this->ueCmdSendNetworkSettingsButton());
    dynamic_cast<QHBoxLayout*>(this->ueButtonsLayout())->addWidget(this->ueButtonQuit());

    dynamic_cast<QHBoxLayout*>(this->ueInfoLayout())->addWidget(this->ueLogWindow(),
                                                                4);

    dynamic_cast<QVBoxLayout*>(this->layout())->addLayout(this->ueInfoLayout(),
                                                          9);
    dynamic_cast<QVBoxLayout*>(this->layout())->addLayout(this->ueButtonsLayout(),
                                                          1);
}   // constructor

UeCentralWidget::~UeCentralWidget()
{
    delete this->ueButtonClear();
    delete this->ueButtonExportTo();
    delete this->ueButtonSearch();
    delete this->ueCmdSendNetworkSettingsButton();
    delete this->ueButtonQuit();

    delete this->ueButtonsLayout();

    delete this->ueLogWindow();
}   // destructor
