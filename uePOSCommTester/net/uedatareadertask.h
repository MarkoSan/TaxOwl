#ifndef UEDATAREADERTASK_H
#define UEDATAREADERTASK_H

#include <QtCore>
#include <QThread>
#include <QRunnable>
#include <QObject>
#include <QList>
#include <QVariant>
#include <QByteArray>
#include <QDataStream>
#include <QDebug>

#include "../net/uedatatransfersocket.h"

/**
 * @brief The UeDataReaderTask class
 */
class UeDataReaderTask : public QThread,
                                QRunnable
{
    Q_OBJECT

private:
    UeDataTransferSocket* m_ueDataTransferSocket;

protected:
    QDataStream m_ueInputDataStream;

public:
    /**
     * @brief UeDataReaderTask
     */
    UeDataReaderTask(UeDataTransferSocket* const dataTransferSocket,
                     QObject* const parent=Q_NULLPTR);

    /**
     * @brief ~UeDataReaderTask
     */
    ~UeDataReaderTask();

    /**
     * @brief run
     */
    void run() override;

    /*!
     * \brief ueDataTransferSocket
     * \return pointer to data transfer socket object
     */
    inline UeDataTransferSocket* ueDataTransferSocket() const
        { return this->m_ueDataTransferSocket; }

    /*!
     * \brief ueSetDataTransferSocket
     * \param socket
     */
    inline void ueSetDataTransferSocket(UeDataTransferSocket* const socket)
        { this->m_ueDataTransferSocket=socket; }

public slots:
    /*!
     * \brief ueSlotReadIncomingData
     */
    void ueSlotReadIncomingData();

    /**
     * @brief ueSlotDataTransferTaskStarted
     */
    void ueSlotDataTransferTaskStarted();

    /**
     * @brief ueSlotDataTransferTaskFinished
     */
    void ueSlotDataTransferTaskFinished();
};

#endif // UEDATAREADERTASK_H
