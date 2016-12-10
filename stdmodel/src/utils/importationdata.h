#ifndef IMPORTATIONDATA_H
#define IMPORTATIONDATA_H

#include "include/definitions.h"

class ImportationData
{

public:
    ImportationData();
    ImportationData(const Filename &);
    importation_code_t importData(ElementsTable& et);


private:
    Filename filename;

};

#endif // IMPORTATIONDATA_H
