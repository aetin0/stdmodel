#include <QCoreApplication>
#include <QtGlobal>

#include "utils/msghandler.h"
#include "worker/worker.h"

int main(int argc, char *argv[])
{
    qInstallMessageHandler(MsgHandler);

    Worker& _worker = Worker::Instance();
    _worker.run();

    return 0;
}

