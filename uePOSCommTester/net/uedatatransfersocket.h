#ifndef UEDATATRANSFERSOCKET_H
#define UEDATATRANSFERSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>

/*!
 * \brief The UeDataTransferSocket class
 */
class UeDataTransferSocket : public QTcpSocket
{
    Q_OBJECT

public:
    /*!
     * \brief UeDataTransferSocket
     * \param parent
     */
    UeDataTransferSocket(QObject* parent=Q_NULLPTR);
};

#endif // UEDATATRANSFERSOCKET_H
