#ifndef UELOGWINDOW_H
#define UELOGWINDOW_H

#include <QPlainTextEdit>
#include <QString>
#include <QDateTime>

#include "uesyntaxhighlighter.h"
#include "uelogentrytype.h"

class UeLogWindow : public QPlainTextEdit
{
    Q_OBJECT

private:
    UeSyntaxHighlighter* m_ueSyntaxHighlighter;

    /*!
     * @brief ueSetSytnaxHighlighter
     * @param syntaxHighLighter
     */
    inline void ueSetSytnaxHighlighter(UeSyntaxHighlighter* const syntaxHighLighter)
        { this->m_ueSyntaxHighlighter=syntaxHighLighter; }

    /*!
     * @brief ueInit
     */
    void ueInit();

public:
    /*!
     * @brief UeLogWindow
     * @param text
     * @param parent
     */
    explicit UeLogWindow(const QString& text=QString(),
                         QWidget* parent=0);

    /*!
     * @brief UeLogWindow
     * @param parent
     */
    UeLogWindow(QWidget* parent=0);

    /*!
     * @brief ~UeLogWindow
     */
    ~UeLogWindow();

    /*!
     * @brief ueSyntaxHighlighter
     * @return pointer to syntax highlighter object
     */
    inline UeSyntaxHighlighter* ueSyntaxHighlighter() const
        { return this->m_ueSyntaxHighlighter; }

    /*!
     * @brief ueCreateLogEntry
     * @param logEntryType
     * @param logText
     * @return object representing log text entry
     */
    static const QString ueCreateLogEntry(const UeLogEntryType& logEntryType,
                                          const QString& logText);
};

#endif // UELOGWINDOW_H
