#include "worker.h"
#include <QDebug>

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
        OrbitalLayers ol= elt.getOrbitalConfiguration();
        QQueue<AtomicOrbital*> ao=ol.getLayers();
        QQueue<AtomicOrbital*>::iterator it=ao.begin();
        for(;it!=ao.end();++it)
            qDebug() << "Element" << elt.getSymbol().toString() << "n=" << (*it)->getN() << ";l=" << (*it)->getL() <<"; NbElectrons : " <<  (*it)->getNbElectronsInOrbital();
    }

    ElementsList elist;
    RequestedElements re;
    re.insert(1,2);//H2
    //re.insert(8,1);//O

    elist = eltPicker.pickElementsFromTable(mdlvTable, re);
//    qDebug() << "Chosen elements::";
//    foreach(Element elt, elist)
//        qDebug() << elt.getSymbol().toByteArray().data() << ";" <<  elt.getAtomicMass();
}
