#include "uesyntaxhiglighter.h"


UeSyntaxHiglighter::UeSyntaxHiglighter(QTextDocument* const parent)
    : QSyntaxHighlighter(parent)
{
    UeHighlightRule ruleInfo;
    UeHighlightRule ruleWarning;
    UeHighlightRule ruleError;
    UeHighlightRule ruleIPv4Address;
    UeHighlightRule rulePortNumber;
    UeHighlightRule ruleProtocolCommand;
    UeHighlightRule ruleProtocolCommandAcknowledge;

    QTextCharFormat ruleInfoFormat;
    QTextCharFormat ruleWarningFormat;
    QTextCharFormat ruleErrorFormat;;
    QTextCharFormat ruleIPv4AddressFormat;
    QTextCharFormat ruleProtocolCommandFormat;
    QTextCharFormat ruleProtocolCommandAcknowledgeFormat;

    ruleInfoFormat.setForeground(Qt::darkBlue);
    ruleInfoFormat.setFontWeight(QFont::ExtraLight);
    ruleInfo.pattern=QRegExp("^\\[INFO\\].*");
    ruleInfo.format=ruleInfoFormat;

    ruleWarningFormat.setForeground(Qt::darkYellow);
    ruleWarningFormat.setFontWeight(QFont::Normal);
    ruleWarning.pattern=QRegExp("^\\[WARNING\\].*");
    ruleWarning.format=ruleWarningFormat;

    ruleErrorFormat.setForeground(Qt::darkRed);
    ruleErrorFormat.setFontWeight(QFont::ExtraBold);
    ruleError.pattern=QRegExp("^\\[ERROR\\].*");
    ruleError.format=ruleErrorFormat;

    ruleIPv4AddressFormat.setFontWeight(QFont::ExtraBold);
    ruleIPv4Address.pattern=QRegExp("(\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3})");
    ruleIPv4Address.format=ruleIPv4AddressFormat;

    //BUG apply same coloring rule to port number as IP address
    rulePortNumber.pattern=QRegExp("(?<=\\bport )\\d+$");
    rulePortNumber.format=ruleIPv4AddressFormat;

    ruleProtocolCommandFormat.setFontCapitalization(QFont::AllUppercase);
    ruleProtocolCommandFormat.setFontWeight(QFont::ExtraBold);
    ruleProtocolCommandFormat.setForeground(Qt::darkGreen);
    //BUG rule is not applied, i.e. text coloring is not active
    ruleProtocolCommand.pattern=QRegExp("^CMD.\\*");
    ruleProtocolCommand.format=ruleProtocolCommandFormat;

    ruleProtocolCommandAcknowledgeFormat.setFontCapitalization(QFont::AllUppercase);
    ruleProtocolCommandAcknowledgeFormat.setFontWeight(QFont::ExtraBold);
    ruleProtocolCommandAcknowledgeFormat.setForeground(Qt::darkMagenta);
    //BUG rule is not applied, i.e. text coloring is not active
    ruleProtocolCommandAcknowledge.pattern=QRegExp("^ACK.\\*");
    ruleProtocolCommandAcknowledge.format=ruleProtocolCommandAcknowledgeFormat;

    m_ueHighlightRules.append(ruleInfo);
    m_ueHighlightRules.append(ruleWarning);
    m_ueHighlightRules.append(ruleError);
    m_ueHighlightRules.append(ruleIPv4Address);
    m_ueHighlightRules.append(rulePortNumber);
    m_ueHighlightRules.append(ruleProtocolCommand);
    m_ueHighlightRules.append(ruleProtocolCommandAcknowledge);
}

UeSyntaxHiglighter::~UeSyntaxHiglighter()
{
}

void UeSyntaxHiglighter::highlightBlock(const QString& text)
{
    foreach(const UeHighlightRule& rule,
            m_ueHighlightRules)
    {
        QRegExp expression(rule.pattern);
        int index=expression.indexIn(text);
        while(index>=0)
        {
            int length=expression.matchedLength();

            this->setFormat(index,
                            length,
                            rule.format);
            index=expression.indexIn(text,
                                     index+length);
        }   // while
    }   // foreach

    setCurrentBlockState(0);
}   // highlightBlock
