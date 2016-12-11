#include <QCoreApplication>
#include <QtGlobal>

#include "utils/msghandler.h"
#include "worker/worker.h"

int main(int argc, char *argv[])
{
    qInstallMessageHandler(MsgHandler);
    QCoreApplication a(argc, argv);

    Worker& _worker = Worker::Instance();
    _worker.run();

    return a.exec();
}

