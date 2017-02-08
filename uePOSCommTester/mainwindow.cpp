#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->ueInitMenu();

    this->ueSetPlacesViewDialog(new UePlacesTableDialog(this));

    this->ueSetCommandsDockWidget(new UeCommandsDockWidget(tr("Commnunication commands"),
                                                           parent));
    this->setCentralWidget(new UeCentralWidget(this));
    connect(dynamic_cast<UeCentralWidget*>(this->centralWidget()),
            SIGNAL(ueSignalNewDataArrivedPlaces(QJsonDocument)),
            this,
            SLOT(ueSlotUpdatePlacesView(QJsonDocument)));

    this->addDockWidget(Qt::LeftDockWidgetArea,
                        this->ueCommandsDockWidget());
    connect(dynamic_cast<UeCommandsWidget*>(this->ueCommandsDockWidget()->widget())->ueCmdDatabasePlacesButton(),
            SIGNAL(clicked()),
            this,
            SLOT(ueSlotCmdDatabasePlacesButton()));
}   // constructor

void MainWindow::ueSlotCmdDatabasePlacesButton()
{
    QList<QVariant> data=QList<QVariant>();
    UeCentralWidget* centralWidget=dynamic_cast<UeCentralWidget*>(this->centralWidget());
    QList<QVariant> hostInfo=QList<QVariant>();
    quint32 dataSize=0;

    hostInfo.append(centralWidget->ueDataTransferSocket()->localAddress().toString());
    hostInfo.append(QString::number(centralWidget->ueDataTransferSocket()->localPort()));
    hostInfo.append(QHostInfo::localHostName());

    data.append(hostInfo);

    if(centralWidget->ueDataTransferSocket()->write(UePOSCommProtocol::ueEncodeCommand(UePosCommProtocolArch::UeCommand::CMD_DATABASE_GET_PLACES,
                                                                                       data,
                                                                                       dataSize))>0)
    {
        centralWidget->ueCommTextEditor()->appendPlainText(centralWidget->ueCommTextEditor()->ueCreateLogEntry(UeLogEntryType::INFO,
                                                                                                               tr("Command").append(" ")
                                                                                                                            .append(UePOSCommProtocol::ueCommandToString(UePosCommProtocolArch::UeCommand::CMD_DATABASE_GET_PLACES))
                                                                                                                            .append(" ")
                                                                                                                            .append(tr("sent to server"))));
    }
    else
    {
        centralWidget->ueCommTextEditor()->appendPlainText(centralWidget->ueCommTextEditor()->ueCreateLogEntry(UeLogEntryType::ERROR,
                                                                                                               tr("Command").append(" ")
                                                                                                                            .append(UePOSCommProtocol::ueCommandToString(UePosCommProtocolArch::UeCommand::CMD_DATABASE_GET_PLACES))
                                                                                                                            .append(" ")
                                                                                                                            .append(tr(" not sent to server"))));
    }   // if
}   // ueSlotCmdDatabasePlacesButton

void MainWindow::ueInitMenu()
{
    this->ueSetCodeRegisterPlacesAction(new QAction(tr("Places"),
                                        this));
    this->ueCodeRegisterPlacesAction()->setShortcut(tr("Ctrl+P"));
    this->ueCodeRegisterPlacesAction()->setStatusTip(tr("Shows places code register"));

    connect(this->ueCodeRegisterPlacesAction(),
            SIGNAL(triggered()),
            this,
            SLOT(ueSlotShowPlacesView()));

    this->ueSetCodeRegisterMenu(this->menuBar()->addMenu(tr("Code register")));
    this->ueCodeRegisterMenu()->addAction(this->ueCodeRegisterPlacesAction());
}   // ueInitMenu

void MainWindow::ueSlotShowPlacesView()
{
    this->uePlacesViewDialog()->exec();
}   // ueSlotShowPlacesView

void MainWindow::ueSlotUpdatePlacesView(const QJsonDocument& newData)
{
//    qDebug() << Q_FUNC_INFO
//             << newData;

    dynamic_cast<UeJsonPlacesTableModel*>(this->uePlacesViewDialog()->uePlacesTableView()->model())->ueSetJsonData(newData);
}   // ueSlotUpdatePlacesView
