#include "uedatareadertask.h"

UeDataReaderTask::UeDataReaderTask(UeDataTransferSocket* const dataTransferSocket,
                                   QObject* const parent)
    : QThread(parent)
{
    this->setAutoDelete(true);
    this->ueSetDataTransferSocket(dataTransferSocket);

    m_ueInputDataStream.setDevice(this->ueDataTransferSocket());
    m_ueInputDataStream.setVersion(QDataStream::Qt_5_8);

    connect(this,
            &QThread::started,
            this,
            &UeDataReaderTask::ueSlotDataTransferTaskStarted);
    connect(this->ueDataTransferSocket(),
            &QIODevice::readyRead,
            this,
            &UeDataReaderTask::ueSlotReadIncomingData);
    connect(this,
            &QThread::finished,
            this,
            &UeDataReaderTask::ueSlotDataTransferTaskFinished);
}   // constructor

UeDataReaderTask::~UeDataReaderTask()
{
}   // destructor

void UeDataReaderTask::run()
{
    this->ueDataTransferSocket()->waitForReadyRead();
}   // run

void UeDataReaderTask::ueSlotReadIncomingData()
{
    QByteArray readData;

    m_ueInputDataStream.startTransaction();

    m_ueInputDataStream >> readData;

    if(m_ueInputDataStream.commitTransaction())
    {
        qDebug() << Q_FUNC_INFO
                 << "readData.size(): "
                 << readData.size();
    }
    else
    {
        return;
    }   // if
}   // ueSlotReadIncomingData

void UeDataReaderTask::ueSlotDataTransferTaskStarted()
{
}   // ueSlotDataTransferTaskStarted

void UeDataReaderTask::ueSlotDataTransferTaskFinished()
{
}   // ueSlotDataTransferTaskFinished
