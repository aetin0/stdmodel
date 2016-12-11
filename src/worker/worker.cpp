#include "worker.h"
#include <stdio.h>

/**
  The worker is a singleton.
  */
 Worker Worker::_worker = Worker();

 /**
  The default constructor
  */
Worker::Worker()
{
    mdlvTable.clear();
}

/**
  The default destructor
  */
Worker::~Worker()
{

}

/**
  This method will return the address of the current worker instancied.
  When the worker is instancied, we access it by calling this method, which return the only worker.
  In this way, we have only one worker living here.
  */
Worker& Worker::Instance()
{
    return _worker;
}

void Worker::run()
{
    importation_code_t ret=IC_ERROR;

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
        printf("%d : %f\n",elt.getAtomicNumber(), elt.getAtomicMass());
    }
}
