#include "worker.h"
#include <stdio.h>

/**
  The worker is a singleton.
  */
Worker Worker::_worker = Worker();

Worker::Worker()
{
    mdlvTable.clear();
}

Worker::~Worker()
{

}

Worker& Worker::Instance()
{
    return _worker;
}

void Worker::run()
{
    int ret=-1;

    dataImporter=ImportationData(ELEMENT_TABLE_PATH);
    ret = dataImporter.importData(mdlvTable);

    if(ret != IC_OK)
        return;

    foreach(Element elt, mdlvTable)
    {
        printf("%d : %f\n",elt.getAtomicNumber(), elt.getAtomicMass());
    }

    ElementsList elist;
    RequestedElements re;
    re.insert(1,2);//H2
    re.insert(8,1);//O

    elist = eltPicker.pickElementsFromTable(mdlvTable, re);
    printf("Chosen elements:::\n");
    foreach(Element elt, elist)
    {
        printf("%s : %f\n",elt.getSymbol().toByteArray().data(), elt.getAtomicMass());
    }
}
