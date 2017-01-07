#ifndef OrbitalLayers_H
#define OrbitalLayers_H

#include <QQueue>

#include "phy/atomicorbital.h"

class OrbitalLayers
{
public:
    OrbitalLayers();

    int addElectronToLayer();
    QQueue<AtomicOrbital*> getLayers(){return layers;}

private:
    void addOrbitalToLayer();
    //QQueue<QString/*1s2, 2s2..*/, AtomicOrbital/*data*/> layers;
    QQueue<AtomicOrbital*> layers;
};

#endif // OrbitalLayers_H

