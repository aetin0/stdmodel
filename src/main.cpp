#include <QCoreApplication>

#include "worker/worker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Worker& _worker = Worker::Instance();
    _worker.run();

    return a.exec();
}

