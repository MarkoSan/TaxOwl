#ifndef UEDATABASESERVERSETTINGSWINDOW_H
#define UEDATABASESERVERSETTINGSWINDOW_H

#include <QDialog>
#include <QSize>
#include <QLineEdit>
#include <QFormLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

class UeDatabaseServerSettingsWindow : public QDialog
{
    Q_OBJECT

private:
    /*!
     * @brief m_ueServerAddressEditor
     */
    QLineEdit* m_ueServerAddressEditor;

    /*!
     * @brief m_ueServerPortEditor
     */
    QLineEdit* m_ueServerPortEditor;

    /*!
     * @brief m_ueDatabaseNameEditor
     */
    QLineEdit* m_ueDatabaseNameEditor;

    /*!
     * @brief m_ueDatabaseUserNameEditor
     */
    QLineEdit* m_ueDatabaseUserNameEditor;

    /*!
     * @brief m_ueDatabasePasswordEditor
     */
    QLineEdit* m_ueDatabasePasswordEditor;

    /*!
     * @brief m_ueButtonsLayout
     */
    QHBoxLayout* m_ueButtonsLayout;

    /*!
     * @brief m_ueTestParametersButton
     */
    QPushButton* m_ueTestParametersButton;

    /*!
     * @brief m_ueSaveSettingsButton
     */
    QPushButton* m_ueSaveSettingsButton;

    /*!
     * @brief m_ueApplySettingsButton
     */
    QPushButton* m_ueApplySettingsButton;

    /*!
     * @brief m_ueEntryFieldsLayout
     */
    QFormLayout* m_ueEntryFieldsLayout;

    /*!
     * @brief ueSetDatabaseServerAddressEditor
     * @param serverAddressEditor
     */
    inline void ueSetDatabaseServerAddressEditor(QLineEdit* const serverAddressEditor)
        { this->m_ueServerAddressEditor=serverAddressEditor; }

    /*!
     * @brief ueSetDatabaseServerPortEditor
     * @param serverPortEditor
     */
    inline void ueSetDatabaseServerPortEditor(QLineEdit* const serverPortEditor)
        { this->m_ueServerPortEditor=serverPortEditor; }

    /*!
     * @brief ueSetDatabaseNameEditor
     * @param databaseNameEditor
     */
    inline void ueSetDatabaseNameEditor(QLineEdit* const databaseNameEditor)
        { this->m_ueDatabaseNameEditor=databaseNameEditor; }

    /*!
     * @brief ueSetDatabaseUserNameEditor
     * @param databaseUserNameEditor
     */
    inline void ueSetDatabaseUserNameEditor(QLineEdit* const databaseUserNameEditor)
        { this->m_ueDatabaseUserNameEditor=databaseUserNameEditor; }

    /*!
     * @brief ueSetDatabasePasswordEditor
     * @param databasePasswordEditor
     */
    inline void ueSetDatabasePasswordEditor(QLineEdit* const databasePasswordEditor)
        { this->m_ueDatabasePasswordEditor=databasePasswordEditor; }

    /*!
     * @brief ueSetButtonsLayout
     * @param buttonsLayout
     */
    inline void ueSetButtonsLayout(QHBoxLayout* const buttonsLayout)
        { this->m_ueButtonsLayout=buttonsLayout; }

    /*!
     * @brief ueSetTestParametersButton
     * @param testConnectionButton
     */
    inline void ueSetTestParametersButton(QPushButton* const testParametersButton)
        { this->m_ueTestParametersButton=testParametersButton; }

    /*!
     * @brief ueSetSaveSettingsButton
     * @param saveSettingsButton
     */
    inline void ueSetSaveSettingsButton(QPushButton* const saveSettingsButton)
        { this->m_ueSaveSettingsButton=saveSettingsButton; }

    /*!
     * @brief ueSetApplySettingsButton
     * @param applySettingsButton
     */
    inline void ueSetApplySettingsButton(QPushButton* const applySettingsButton)
        { this->m_ueApplySettingsButton=applySettingsButton; }

    /*!
     * @brief ueSetEntryFieldsLayout
     * @param layout
     */
    inline void ueSetEntryFieldsLayout(QFormLayout* const layout)
        { this->m_ueEntryFieldsLayout=layout; }

public:
    explicit UeDatabaseServerSettingsWindow(QWidget* parent=Q_NULLPTR,
                                            Qt::WindowFlags f=Qt::Dialog/*|Qt::FramelessWindowHint*/);

    /*!
     * @brief ueDatabaserServerAddressEditor
     * @return pointer to object representing server address editor
     */
    inline QLineEdit* ueDatabaserServerAddressEditor() const
        { return this->m_ueServerAddressEditor; }

    /*!
     * @brief ueDatabaseServerPortEditor
     * @return pointer to object representing server port editor
     */
    inline QLineEdit* ueDatabaseServerPortEditor() const
        { return this->m_ueServerPortEditor; }

    /*!
     * @brief ueDatabaseNameEditor
     * @return pointer to object representing database name editor
     */
    inline QLineEdit* ueDatabaseNameEditor() const
        { return this->m_ueDatabaseNameEditor; }

    /*!
     * @brief ueDatabaseUserNameEditor
     * @return pointer to object representing database username editor
     */
    inline QLineEdit* ueDatabaseUserNameEditor() const
        { return this->m_ueDatabaseUserNameEditor; }

    /*!
     * @brief ueDatabasePasswordEditor
     * @return pointer to object representing database password editor
     */
    inline QLineEdit* ueDatabasePasswordEditor() const
        { return this->m_ueDatabasePasswordEditor; }

    /*!
     * @brief ueButtonsLayout
     * @return pointer to object representing buttons layout
     */
    inline QHBoxLayout* ueButtonsLayout() const
        { return this->m_ueButtonsLayout; }

    /*!
     * @brief ueTestParametersButton
     * @return pointer to object representing test connection button
     */
    inline QPushButton* ueTestParametersButton() const
        { return this->m_ueTestParametersButton; }

    /*!
     * @brief ueSaveSettingsButton
     * @return pointer to object representing save settings button
     */
    inline QPushButton* ueSaveSettingsButton() const
        { return this->m_ueSaveSettingsButton; }

    /*!
     * @brief ueApplySettingsButton
     * @return pointer to object representing apply settings button
     */
    inline QPushButton* ueApplySettingsButton() const
        { return this->m_ueApplySettingsButton; }

    /*!
     * @brief ueEntryFieldsLayout
     * @return pointer to object representing entry fields layout
     */
    inline QFormLayout* ueEntryFieldsLayout() const
        { return this->m_ueEntryFieldsLayout; }

    /*!
     * @brief sizeHint
     * @return widget size hint
     */
//    inline QSize sizeHint() const
//        { return QSize(640, 480 ); }
};

#endif // UEDATABASESERVERSETTINGSWINDOW_H
