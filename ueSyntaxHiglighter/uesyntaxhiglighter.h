#ifndef UESYNTAXHIGLIGHTER_H
#define UESYNTAXHIGLIGHTER_H

#include <QSyntaxHighlighter>
#include <QTextDocument>
#include <QRegExp>
#include <QTextCharFormat>
#include <QVector>
#include <QString>

#include "uehighlightrule.h"

class UeSyntaxHiglighter : public QSyntaxHighlighter
{
    Q_OBJECT

private:
    QVector<UeHighlightRule> m_ueHighlightRules;

public:
    UeSyntaxHiglighter(QTextDocument* const parent=0);
    ~UeSyntaxHiglighter();

    /*!
     * @brief highlightBlock
     * @param text
     */
    void highlightBlock(const QString& text);

    /*!
     * @brief ueHighlightRules
     * @return pointer to vector of pointer to highlight rules object
     */
    inline const QVector<UeHighlightRule>& ueHighlightRules() const
        { return this->m_ueHighlightRules; }
};

#endif // UESYNTAXHIGLIGHTER_H
