#ifndef UEHIGHLIGHTRULE_H
#define UEHIGHLIGHTRULE_H

#include <QRegExp>
#include <QTextCharFormat>

/*!
 * @brief The UeHighlightRule struct
 */
struct UeHighlightRule
{
    QRegExp pattern;
    QTextCharFormat format;
};

#endif // UEHIGHLIGHTRULE_H
