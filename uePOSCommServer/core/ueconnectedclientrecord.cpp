#include "ueconnectedclientrecord.h"

UeConnectedClientRecord::UeConnectedClientRecord(const QString& clientName,
                                                 const QHostAddress& clientAddress,
                                                 const QString& clientPort,
                                                 const QString& clientOS)
{
    this->ueSetClientName(clientName);
    this->ueSetClientAddress(clientAddress);
    this->ueSetClientPort(clientPort);
    this->ueSetClientOS(clientOS);
}   // constructor
