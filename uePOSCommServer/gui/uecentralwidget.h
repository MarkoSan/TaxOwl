#ifndef UECENTRALWIDGET_H
#define UECENTRALWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

#include "../ueSyntaxHighlighter/uelogwindow.h"
#include "../uePOSCommProtocol/ueposcommprotocol.h"

class UeCentralWidget : public QWidget
{
    Q_OBJECT

private:
    /*!
     * @brief m_ueLogWindow
     */
    UeLogWindow* m_ueLogWindow;

    /*!
     * @brief m_ueButtonsLayout
     */
    QHBoxLayout* m_ueButtonsLayout;

    /*!
     * @brief m_ueButtonClear
     */
    QPushButton* m_ueButtonClear;

    /*!
     * @brief m_ueButtonExportTo
     */
    QPushButton* m_ueButtonExportTo;

    /*!
     * @brief m_ueButtonSearch
     */
    QPushButton* m_ueButtonSearch;

    /*!
     * @brief m_ueCmdSendNetworkSettingsButton
     */
    QPushButton* m_ueCmdSendNetworkSettingsButton;

    /*!
     * @brief m_ueButtonQuit
     */
    QPushButton* m_ueButtonQuit;

    /*!
     * @brief m_ueInfoLayout
     */
    QHBoxLayout* m_ueInfoLayout;

protected:
    /*!
     * @brief ueSetLogWindow
     * @param logWindow
     */
    inline void ueSetLogWindow(UeLogWindow* const logWindow)
        { this->m_ueLogWindow=logWindow; }

    /*!
     * @brief ueSetButtonsLayout
     * @param layout
     */
    inline void ueSetButtonsLayout(QHBoxLayout* const layout)
        { this->m_ueButtonsLayout=layout; }

    /*!
     * @brief ueSetButtonClear
     * @param button
     */
    inline void ueSetButtonClear(QPushButton* const button)
        { this->m_ueButtonClear=button; }

    /*!
     * @brief ueSetButtonExportTo
     * @param button
     */
    inline void ueSetButtonExportTo(QPushButton* const button)
        { this->m_ueButtonExportTo=button; }

    /*!
     * @brief ueSetButtonSearch
     * @param button
     */
    inline void ueSetButtonSearch(QPushButton* const button)
        { this->m_ueButtonSearch=button; }

    /*!
     * @brief ueSetCmdSendNetworkSettingsButton
     * @param button
     */
    inline void ueSetCmdSendNetworkSettingsButton(QPushButton* const button)
        { this->m_ueCmdSendNetworkSettingsButton=button; }

    /*!
     * @brief ueSetButtonQuit
     * @param button
     */
    inline void ueSetButtonQuit(QPushButton* const button)
        { this->m_ueButtonQuit=button; }

    /*!
     * @brief ueSetInfoLayout
     * @param layout
     */
    inline void ueSetInfoLayout(QHBoxLayout* const layout)
        { this->m_ueInfoLayout=layout; }

public:
    /*!
     * @brief UeCentralWidget
     * @param parent
     */
    explicit UeCentralWidget(QWidget *parent = 0);

    /*!
     * @brief UeCentralWidget
     */
    ~UeCentralWidget();

    /*!
     * @brief ueLogWindow
     * @return pointer to object representing log window
     */
    inline UeLogWindow* ueLogWindow() const
        { return this->m_ueLogWindow; }

    /*!
     * @brief ueButtonsLayout
     * @return pointer to object representing buttons layout
     */
    inline QHBoxLayout* ueButtonsLayout() const
        { return this->m_ueButtonsLayout; }

    /*!
     * @brief ueButtonClear
     * @return pointer to object representing button "clear"
     */
    inline QPushButton* ueButtonClear() const
        { return this->m_ueButtonClear; }

    /*!
     * @brief ueButtonExportTo
     * @return pointer to object representing button "export to"
     */
    inline QPushButton* ueButtonExportTo() const
        { return this->m_ueButtonExportTo; }

    /*!
     * @brief ueButtonSearch
     * @return pointer to object representing button "search"
     */
    inline QPushButton* ueButtonSearch() const
        { return this->m_ueButtonSearch; }

    /*!
     * @brief ueCmdSendNetworkSettingsButton
     * @return pointer to object representing get network settings command button
     */
    inline QPushButton* ueCmdSendNetworkSettingsButton() const
        { return this->m_ueCmdSendNetworkSettingsButton; }

    /*!
     * @brief ueButtonQuit
     * @return pointer to object representing button "quit"
     */
    inline QPushButton* ueButtonQuit() const
        { return this->m_ueButtonQuit; }

    /*!
     * @brief ueInfoLayout
     * @return pointer to object representing info layout
     */
    inline QHBoxLayout* ueInfoLayout() const
        { return this->m_ueInfoLayout; }
};

#endif // UECENTRALWIDGET_H
