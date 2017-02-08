#include "uelogwindow.h"

UeLogWindow::UeLogWindow(const QString& text,
                         QWidget* parent)
    : QPlainTextEdit(text,
                     parent)
{
    this->ueInit();
}   // constructor

UeLogWindow::UeLogWindow(QWidget* parent)
    : QPlainTextEdit(parent)
{
    this->ueInit();
}   // constructor

UeLogWindow::~UeLogWindow()
{
    delete this->ueSyntaxHighlighter();
}   // destructor

void UeLogWindow::ueInit()
{
    this->setCursorWidth(8);
    this->setReadOnly(true);
    this->ueSetSytnaxHighlighter(new UeSyntaxHiglighter(this->document()));
}   // ueInit

const QString UeLogWindow::ueCreateLogEntry(const UeLogEntryType& logEntryType,
                                            const QString& logText)
{
    QString result=QString();
    QString timeStamp=QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss:zzz");

    switch(logEntryType)
    {
        case UeLogEntryType::INFO:
        {
            result=tr("[INFO]");

            break;
        }   // case

        case UeLogEntryType::WARNING:
        {
            result=tr("[WARNING]");

            break;
        }   // case

        case UeLogEntryType::ERROR:
        {
            result=tr("[ERROR]");

            break;
        }   // case
    }   // switch

    result.append(" ")
          .append(timeStamp)
          .append(" ")
          .append(logText);

    return result;
}   // ueCreateLogEntry
