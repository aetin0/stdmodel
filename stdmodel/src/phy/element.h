#ifndef ELEMENT_H
#define ELEMENT_H

#include <stdint.h>
#include <QVariant>

#include "include/definitions.h"
/*
 * Element : Mendeleev's table
*/

class Element
{
public:
    Element();
    ~Element();

    void setAtomicNumber(const uint8_t an);
    uint8_t getAtomicNumber(){return atomicNumber;}

    void setAtomicMass(const double am);
    double getAtomicMass(){return atomicMass;}

    void setOxidationState(const uint8_t os);
    uint8_t getOxidationState(){return oxidationState;}

    void setSymbol(const QVariant s);
    QVariant getSymbol(){return symbol;}

    void setCategory(const element_category_t ec);
    element_category_t getCategory(){return category;}


private:
    uint8_t                 atomicNumber;
    double                  atomicMass;
    uint8_t                 oxidationState;
    QVariant                symbol;
    element_category_t      category;

};

#endif // ELEMENT_H
