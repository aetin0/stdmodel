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
    dataImporter=ImportationData(ELEMENT_TABLE_PATH);
    dataImporter.importData(mdlvTable);

    foreach(Element elt, mdlvTable)
    {
        printf("%d : %f\n",elt.getAtomicNumber(), elt.getAtomicMass());
    }
}
