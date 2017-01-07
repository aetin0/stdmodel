#include "phy/orbitallayers.h"
#include "phy/atomicorbital.h"
#include <QString>
#include <QDebug>

OrbitalLayers::OrbitalLayers()
{
    //create layers
    layers.push_back(new AtomicOrbital(1,0));
}

int OrbitalLayers::addElectronToLayer()
{
    int ret=-1;

    AtomicOrbital* lastOrbital = layers.last();
    if(lastOrbital->isOrbitalFull())
    {
        qDebug() << "orbital n=" << lastOrbital->getN() << "; l=" << lastOrbital->getL() << " is full";
        addOrbitalToLayer();
    }

    lastOrbital = layers.last();

    if(!lastOrbital->isOrbitalFull())
        lastOrbital->addElectronToOrbital(lastOrbital->getN(), lastOrbital->getL());
    else
        qWarning() << "orbital is full";

    return ret;
}

void OrbitalLayers::addOrbitalToLayer()
{
    AtomicOrbital* lastOrbital = layers.last();
    quint8 lastN = lastOrbital->getN();
    qint8 lastL = lastOrbital->getL();

    //TODO : introduce energy comparison
    quint8 levels[19] = {10, 20, 21, 30, 31, 40, 32, 41, 50, 42, 51, 60, 43, 52, 61, 70, 53, 62, 71};

    quint8 nb=lastN*10 + lastL;
    quint8* ptr=&(levels[0]);
    while(ptr != NULL && *ptr != nb)
        ptr++;
    if((ptr++) != NULL)
        nb=*(ptr++);
    else
        return;

    quint8 newN=nb/10;
    qint8 newL=nb-(newN*10);

    layers.push_back(new AtomicOrbital(newN, newL));
}
