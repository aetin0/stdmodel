#ifndef WORKER_H
#define WORKER_H

#include "phy/element.h"
#include "utils/importationdata.h"
#include "include/definitions.h"

/**
 * singleton
 */
class Worker
{

private:
    Worker(const Worker &);
    Worker &operator=(const Worker &);

    static Worker _worker;
    Worker();
    ~Worker();


    ElementsTable                   mdlvTable;
    ImportationData                 dataImporter;

public:
    static Worker& Instance();
    void run();

};
#endif // WORKER_H
