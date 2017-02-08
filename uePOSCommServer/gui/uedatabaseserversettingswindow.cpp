#include "uedatabaseserversettingswindow.h"

UeDatabaseServerSettingsWindow::UeDatabaseServerSettingsWindow(QWidget* parent,
                                                               Qt::WindowFlags f)
    : QDialog(parent)
{
    this->setWindowFlags(f);
    this->setWindowTitle(tr("Database server settings"));

    this->setLayout(new QVBoxLayout);

    this->ueSetDatabaseServerAddressEditor(new QLineEdit(this));
    this->ueSetDatabaseServerPortEditor(new QLineEdit(this));
    this->ueSetDatabaseNameEditor(new QLineEdit(this));
    this->ueSetDatabaseUserNameEditor(new QLineEdit(this));
    this->ueSetDatabasePasswordEditor(new QLineEdit(this));

    this->ueSetEntryFieldsLayout(new QFormLayout);

    this->ueEntryFieldsLayout()->addRow(new QLabel(tr("Server address:"),
                                                   this),
                                        this->ueDatabaserServerAddressEditor());
    this->ueEntryFieldsLayout()->addRow(new QLabel(tr("Server port:"),
                                                   this),
                                        this->ueDatabaseServerPortEditor());
    this->ueEntryFieldsLayout()->addRow(new QLabel(tr("Database name:"),
                                                   this),
                                        this->ueDatabaseNameEditor());
    this->ueEntryFieldsLayout()->addRow(new QLabel(tr("Database username:"),
                                                   this),
                                        this->ueDatabaseUserNameEditor());
    this->ueEntryFieldsLayout()->addRow(new QLabel(tr("Database password:"),
                                                   this),
                                        this->ueDatabasePasswordEditor());

    this->ueDatabasePasswordEditor()->setEchoMode(/*QLineEdit::PasswordEchoOnEdit*/QLineEdit::Password);

    this->ueSetButtonsLayout(new QHBoxLayout);

    this->ueSetTestParametersButton(new QPushButton(tr("Test parameters"),
                                                    this));
    this->ueSetSaveSettingsButton(new QPushButton(tr("Save settings"),
                                                  this));
    this->ueSetApplySettingsButton(new QPushButton(tr("Apply settings"),
                                                   this));

    this->ueButtonsLayout()->addWidget(this->ueTestParametersButton());
    this->ueButtonsLayout()->addWidget(this->ueSaveSettingsButton());
    this->ueButtonsLayout()->addWidget(this->ueApplySettingsButton());

    this->layout()->addItem(this->ueEntryFieldsLayout());
    this->layout()->addItem(this->ueButtonsLayout());

    this->setModal(true);
}   // constructor
