#include <QDebug>
#include <QDebug>
#include "atomicorbital.h"


OrbitalStructure::OrbitalStructure()
{
    spinUp=false;//not filled
    spinDown=false;//not filled
}

bool OrbitalStructure::storeElectronToOrbital(quint8 n, qint8 l, qint8 ml, electron_spin_t s)
{
    bool ret=true;

    if(electrons.size() == 2)
    {
        qWarning() << "storeElectronToOrbital() : no more space here";
        return false;
    }

    Electron* e = new Electron(n,l,ml,s);

    if(s == E_SPIN_UP)
    {
        if(!spinUp)
        {
            spinUp=true;
            electrons.append(e);
        }
        else
            ret=false;
    }
    else if(s == E_SPIN_DOWN)
    {
        if(!spinDown && spinUp)
        {
            spinDown=true;
            electrons.append(e);
        }
        else
            ret=false;
    }
    else
        return false;
#ifdef VERBOSE
    qDebug() << "electron e(" << e->getN() << "," << e->getL() << "," << e->getML() << "," << (qint8)e->getSPIN() << ") added";
#endif
    return ret;
}

bool OrbitalStructure::isFull()
{
    return (spinDown && spinUp);
}

/* ****************** */

AtomicOrbital::AtomicOrbital(quint8 a, qint8 b): n(a), l(b)
{
    //qDebug() << "creation of orbital n=" << a << "; l=" << b;
    switch (l)
    {
    case 0:
        maxElectronNb=2;//s
        break;
    case 1:
        maxElectronNb=6;//p
        break;
    case 2:
        maxElectronNb=10;//d
        break;
    case 3:
        maxElectronNb=14;//f
        break;
    case 4:
        maxElectronNb=18;//g
        break;

    default:
        maxElectronNb=-1;
        break;
    }
    isFull=false;
    electronsNb=0;
    createOrbital();
}

int AtomicOrbital::addElectronToOrbital(quint8 n, qint8 l)
{
    int ret=-1;
    qint8 ml=0;

    isOrbitalFull();

    if(isFull)
    {
        qWarning() << "addElectronToOrbital : orbital is FULL";
        return ret;
    }

    QQueue<OrbitalStructure*>::iterator it=orbital.begin();

    //research algorithm for the place to take..

    for(;it!=orbital.end() && (*it)->hasSpinUp();++it);

    if(it != orbital.end())
    {
       (*it)->storeElectronToOrbital(n, l, ml, E_SPIN_UP);
       electronsNb=(int)(it-orbital.begin())+1;
    }
    else
    {
        it=orbital.begin();
        for(;it!=orbital.end() && (*it)->hasSpinDown();++it);

        if(it != orbital.end())
            (*it)->storeElectronToOrbital(n, l, ml, E_SPIN_DOWN);

        electronsNb=(int)((it-orbital.begin()))+orbital.size()+1;
    }
    return ret;
}

bool AtomicOrbital::isOrbitalFull()
{
    bool full=true;
    QQueue<OrbitalStructure*>::iterator it=orbital.begin();

    for(;it!=orbital.end();++it)
    {
        if(!(*it)->isFull())
        {
            full=false;
            break;
        }
    }
    if(it!=orbital.end())
        full=false;

    isFull=full;

    return full;
}

void AtomicOrbital::createOrbital()
{
    int holders=maxElectronNb/2;

    for(int i=0; i<holders;++i)
    {
        orbital.append(new OrbitalStructure());
    }
}

