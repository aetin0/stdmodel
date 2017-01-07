#ifndef ATOMICORBITAL_H
#define ATOMICORBITAL_H

#include <QQueue>

#include "electron.h"

class OrbitalStructure
{
public:
    OrbitalStructure();

    bool storeElectronToOrbital(quint8 n, qint8 l, qint8 ml, electron_spin_t s);
    bool addSpinDown();
    bool hasSpinUp(){return spinUp;}
    bool hasSpinDown(){return spinDown;}
    bool isFull();

private:
    bool spinUp;
    bool spinDown;
    QList<Electron*> electrons;
};

class AtomicOrbital
{
public:
    AtomicOrbital(quint8 a, qint8 b);

    int         addElectronToOrbital(quint8 n, qint8 l);
    bool        isOrbitalFull();
    int         amountOfElectrons(){return electronsNb;}
    void        createOrbital();
    int         getNbElectronsInOrbital(){return electronsNb;}
    quint8      getN(){return n;}
    qint8       getL(){return l;}


protected:
    QQueue<OrbitalStructure*> orbital;
    int                     maxElectronNb;
    int                     electronsNb;
    bool                    isFull;
    quint8                  n;
    qint8                   l;
};


#endif // ATOMICORBITAL_H
