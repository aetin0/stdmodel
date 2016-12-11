#include "msghandler.h"
#include <stdio.h>
#include <stdlib.h>
#include <QCoreApplication>

void MsgHandler(QtMsgType type, const QMessageLogContext &, const QString & str)
{
    switch (type)
    {
        #ifndef QT_NO_DEBUG_OUTPUT
        case QtDebugMsg:
            printf("[DEBUG]: %s\n", str.toStdString().c_str());
            break;
        #endif
        case QtWarningMsg:
            printf("[WARNING]: %s\n", str.toStdString().c_str());
            break;
        case QtCriticalMsg:
            printf("[CRITICAL]: %s\n", str.toStdString().c_str());
            break;
        case QtFatalMsg:
            printf("[FATAL]: %s\n", str.toStdString().c_str());
            qApp->quit();
    }
}
