#ifndef UECENTRALWIDGET_H
#define UECENTRALWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QCheckBox>
#include <QApplication>
#include <QByteArray>
#include <QString>
#include <QHostAddress>
#include <QList>
#include <QVariant>
#include <QHostInfo>
#include <QSysInfo>

#include <QJsonDocument>

#include <QDebug>

#include "../uePOSCommProtocol/ueposcommprotocol.h"
#include "../ueSyntaxHighlighter/uelogwindow.h"
#include "../uePOSCommProtocol/uedefaults.h"
#include "net/uenetworkdiscoverysocket.h"
#include "net/uedatatransfersocket.h"
#include "net/uedatareadertask.h"

/*!
 * @brief The UeCentralWidget class
 */
class UeCentralWidget : public QWidget
{
    Q_OBJECT

private:
    /*!
     * @brief m_ueButtonsLayout
     */
    QHBoxLayout* m_ueButtonsLayout;

    /*!
     * @brief m_ueCommandsEditor
     */
//    UeLogWindow* m_ueCommandsEditor;

    /*!
     * @brief m_ueOptionsLayout
     */
    QHBoxLayout* m_ueOptionsLayout;

    /*!
     * @brief m_ueHexCheckBox
     */
    QCheckBox* m_ueHexCheckBox;

    /*!
     * @brief m_ueDirectSendCheckBox
     */
    QCheckBox* m_ueDirectSendCheckBox;

    /*!
     * @brief m_ueSendButton
     */
    QPushButton* m_ueSendButton;

    /*!
     * @brief m_ueClearButton
     */
    QPushButton* m_ueClearButton;

    /*!
     * @brief m_ueCloseButton
     */
    QPushButton* m_ueCloseButton;

    /**
     * @brief m_ueNetworkDiscoverySocket
     */
    UeNetworkDiscoverySocket* m_ueNetworkDiscoverySocket;

    /*!
     * @brief m_ueCommTextEditor
     */
    UeLogWindow* m_ueCommTextEditor;

    /**
     * @brief m_ueDataTransferSocket
     */
    UeDataTransferSocket* m_ueDataTransferSocket;

    /*!
     * \brief m_ueDataReaderTask
     */
    UeDataReaderTask* m_ueDataReaderTask;

    /*!
     * @brief ueSetOptionsLayout
     * @param layout
     */
    inline void ueSetOptionsLayout(QHBoxLayout* const layout)
        { this->m_ueOptionsLayout=layout; }

    /*!
     * @brief ueSetButtonsLayout
     * @param layout
     */
    inline void ueSetButtonsLayout(QHBoxLayout* const layout)
        { this->m_ueButtonsLayout=layout; }

    /*!
     * @brief ueSetHexCheckBox
     * @param box
     */
    inline void ueSetHexCheckBox(QCheckBox* const box)
        { this->m_ueHexCheckBox=box; }

    /*!
     * @brief ueSetDirectSendCheckBox
     * @param box
     */
    inline void ueSetDirectSendCheckBox(QCheckBox* const box)
        { this->m_ueDirectSendCheckBox=box; }

    /*!
     * @brief ueSetSendButton
     * @param button
     */
    inline void ueSetSendButton(QPushButton* const button)
        { this->m_ueSendButton=button; }

    /*!
     * @brief ueSetClearButton
     * @param button
     */
    inline void ueSetClearButton(QPushButton* const button)
        { this->m_ueClearButton=button; }

    /*!
     * @brief ueSetCloseButton
     * @param button
     */
    inline void ueSetQuitButton(QPushButton* const button)
        { this->m_ueCloseButton=button; }

    /*!
     * @brief ueSetCommandTransferSocket
     * @param socket
     */
    inline void ueSetNetworkDiscoverySocket(UeNetworkDiscoverySocket* const socket)
        { this->m_ueNetworkDiscoverySocket=socket; }

    /*!
     * @brief ueSetCommTextEditor
     * @param editor
     */
    inline void ueSetCommTextEditor(UeLogWindow* const editor)
        { this->m_ueCommTextEditor=editor; }

    /**
     * @brief ueSetDataTransferSocket
     * @param socket
     */
    inline void ueSetDataTransferSocket(UeDataTransferSocket* const socket)
        { this->m_ueDataTransferSocket=socket; }

    /**
     * @brief ueSetDataReaderTask
     * @param task
     */
    inline void ueSetDataReaderTask(UeDataReaderTask* const task)
        { this->m_ueDataReaderTask=task; }

public:
    /*!
     * @brief UeCentralWidget
     * @param parent
     */
    explicit UeCentralWidget(QWidget *parent = 0);

    /*!
     * @brief ueButtonsLayout
     * @return pointer to object representing buttons layout
     */
    inline QHBoxLayout* ueButtonsLayout() const
        { return this->m_ueButtonsLayout; }

    /*!
     * @brief ueCommandsEditor
     * @return pointer to object representing commands editor
     */
/*
    inline UeLogWindow* ueCommandsEditor() const
        { return this->m_ueCommandsEditor; }
*/

    /*!
     * @brief ueOptionsLayout
     * @return pointer to object representing options layout
     */
    inline QHBoxLayout* ueOptionsLayout() const
        { return this->m_ueOptionsLayout; }

    /*!
     * @brief ueHexCheckBox
     * @return pointer to object representing check box for toggling hex mode on off
     */
    inline QCheckBox* ueHexCheckBox() const
        { return this->m_ueHexCheckBox; }

    /*!
     * @brief ueDirectSendCheckBox
     * @return pointer to object representing check box for direct sending (without pressing CR/LF)
     */
    inline QCheckBox* ueDirectSendCheckBox() const
        { return this->m_ueDirectSendCheckBox; }

    /*!
     * @brief ueSendButton
     * @return pointer to object representing send button
     */
    inline QPushButton* ueSendButton() const
        { return this->m_ueSendButton; }

    /*!
     * @brief ueClearButton
     * @return pointer to object representing clear button
     */
    inline QPushButton* ueClearButton() const
        { return this->m_ueClearButton; }

    /*!
     * @brief ueQuitButton
     * @return pointer to object representing close button
     */
    inline QPushButton* ueQuitButton() const
        { return this->m_ueCloseButton; }

    /*!
     * @brief ueNetworkDiscoverySocket
     * @return pointer to object representing network discovery socket
     */
    inline UeNetworkDiscoverySocket* ueNetworkDiscoverySocket() const
        { return this->m_ueNetworkDiscoverySocket; }

    /*!
     * @brief ueCommTextEditor
     * @return pointer to object representing tcp communication editor
     */
    inline UeLogWindow* ueCommTextEditor() const
        { return this->m_ueCommTextEditor; }

    /**
     * @brief ueDataTransferSocket
     * @return pointer to object representing data transfer socket
     */
    inline UeDataTransferSocket* ueDataTransferSocket() const
        { return this->m_ueDataTransferSocket; }

    /**
     * @brief ueDataReaderTask
     * @return pointer to object representing data reader task (thread)
     */
    inline UeDataReaderTask* ueDataReaderTask() const
        { return this->m_ueDataReaderTask; }

signals:
    /**
     * @brief ueSignalNewDataArrivedPlaces
     * @param data
     */
    void ueSignalNewDataArrivedPlaces(const QJsonDocument& data);

public slots:
    /*!
     * @brief ueSlotHexModeClick
     * @param state
     */
    void ueSlotHexModeClick(int state);

    /*!
     * @brief ueSlotDirectSendClick
     * @param state
     */
    void ueSlotDirectSendClick(int state);

    /*!
     * @brief ueSlotSendButtonClick
     */
    void ueSlotSendButtonClick();

    /*!
     * @brief ueSlotClearButtonClick
     */
    void ueSlotClearButtonClick();

    /*!
     * @brief ueSlotCloseButtonClick
     */
    void ueSlotQuitButtonClick();

    /*!
     * @brief ueSlotReadSocketData
     */
    void ueSlotReadNetworkDiscoverySocketData();

    /**
     * @brief ueSlotReadCommunicationsSocketData
     */
    void ueSlotReadDataTransferSocketData();

    /**
     * @brief ueSlotCommunicationsSocletStateChanged
     * @param socketState
     */
    void ueSlotDataTransferSocketStateChanged(QAbstractSocket::SocketState socketState);

    /**
     * @brief ueSlotCommunicationsSocketHostFound
     */
    void ueSlotDataTransferSocketHostFound();

    /**
     * @brief ueSlotCommunicationsSocketConnected
     */
    void ueSlotDataTransferSocketConnected();

    /**
     * @brief ueSlotCommunicationsSocketDisconnected
     */
    void ueSlotDataTransferSocketDisconnected();

    /**
     * @brief ueSlotNetworkDiscoverySocketConnected
     */
    void ueSlotNetworkDiscoverySocketConnected();

    /**
     * @brief ueSlotNetworkDiscoverySocketDisconnected
     */
    void ueSlotNetworkDiscoverySocketDisconnected();

    /**
     * @brief ueSlotNetworkDiscoverySocketError
     * @param socketError
     */
    void ueSlotNetworkDiscoverySocketError(QAbstractSocket::SocketError socketError);

    /**
     * @brief ueSlotNetworkDiscoverySocketHostFound
     */
    void ueSlotNetworkDiscoverySocketHostFound();

    /**
     * @brief ueSlotNetworkDiscoverySocketStateChanged
     * @param socketState
     */
    void ueSlotNetworkDiscoverySocketStateChanged(QAbstractSocket::SocketState socketState);
};

#endif // UECENTRALWIDGET_H
