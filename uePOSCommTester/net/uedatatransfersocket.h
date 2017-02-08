#ifndef UEDATATRANSFERSOCKET_H
#define UEDATATRANSFERSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>

class UeDataTransferSocket : public QTcpSocket
{
    Q_OBJECT

public:
    UeDataTransferSocket(QObject* parent=Q_NULLPTR);
};

#endif // UEDATATRANSFERSOCKET_H
