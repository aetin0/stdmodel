#ifndef ELECTRON_H
#define ELECTRON_H

#include <QtGlobal>
#include <QVector>

typedef enum spin{
    E_SPIN_DOWN=0,
    E_SPIN_UP=1
}electron_spin_t;

class Electron
{
public:
    Electron(quint8 n, qint8 l, qint8 ml, electron_spin_t s);
    ~Electron();
    QVector<qint8> getElectronIdentity();

    void setN(qint8 a);
    void setL(qint8 a);
    void setML(qint8 a);
    void setSPIN(electron_spin_t a);

    quint8 getN(){return n;}
    qint8 getL(){return l;}
    qint8 getML(){return ml;}
    electron_spin_t getSPIN(){return spin;}

private:
    quint8  n;
    qint8   l;
    qint8   ml;
    electron_spin_t spin;
};

#endif // ELECTRON_H
