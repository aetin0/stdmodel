#include "electron.h"

Electron::Electron(quint8 a, qint8 b, qint8 c, electron_spin_t d): n(a), l(b), ml(c), spin(d)
{

}

Electron::~Electron()
{

}


QVector<qint8> Electron::getElectronIdentity()
{
    QVector<qint8> vect;

    //well, return only qint8
    //TODO: change this hack
    if(n<128)
    {
        vect.append(n);
        vect.append(l);
        vect.append(ml);
        vect.append((qint8)spin);
    }

    return vect;
}

void Electron::setN(qint8 a)
{
    n=a;
}

void Electron::setL(qint8 a)
{
    l=a;
}

void Electron::setML(qint8 a)
{
    ml=a;
}

void Electron::setSPIN(electron_spin_t a)
{
    spin=a;
}
