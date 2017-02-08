#ifndef UENETWORKDISCOVERYSOCKET_H
#define UENETWORKDISCOVERYSOCKET_H

#include <QObject>
#include <QUdpSocket>

class UeNetworkDiscoverySocket : public QUdpSocket
{
public:
    UeNetworkDiscoverySocket(QObject* parent=Q_NULLPTR);
};

#endif // UENETWORKDISCOVERYSOCKET_H
