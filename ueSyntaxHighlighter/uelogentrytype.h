#ifndef UELOGENTRYTYPE_H
#define UELOGENTRYTYPE_H

#include <QtGlobal>

enum class UeLogEntryType : quint8
{
    INFO=0x00,
    WARNING=0x01,
    ERROR=0x02,
};

#endif // UELOGENTRYTYPE_H
