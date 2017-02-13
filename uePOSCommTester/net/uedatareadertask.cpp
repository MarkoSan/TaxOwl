#include "uedatareadertask.h"

UeDataReaderTask::UeDataReaderTask(UeDataTransferSocket* const dataTransferSocket,
                                   QObject* const parent)
    : QThread(parent)
{
    this->setAutoDelete(true);
    this->ueSetDataTransferSocket(dataTransferSocket);

    m_ueInputDataStream.setDevice(this->ueDataTransferSocket());
    m_ueInputDataStream.setVersion(QDataStream::Qt_5_8);

    connect(this->ueDataTransferSocket(),
            &QIODevice::readyRead,
            this,
            &UeDataReaderTask::ueSlotReadIncomingData);
}   // constructor

UeDataReaderTask::~UeDataReaderTask()
{
}   // destructor

void UeDataReaderTask::run()
{
    m_ueInputDataStream.startTransaction();

    if(!m_ueInputDataStream.commitTransaction())
    {
        return;
    }   // if
}   // run

void UeDataReaderTaskueSlotReadIncomingData()
{
}   // ueSlotReadIncomingData
