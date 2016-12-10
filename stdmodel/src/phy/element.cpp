#include "element.h"


Element::Element()
{

}

Element::~Element()
{

}

void Element::setAtomicNumber(const uint8_t an)
{
    atomicNumber=an;
}

void Element::setAtomicMass(const double am)
{
    atomicMass=am;
}

void Element::setOxidationState(const uint8_t os)
{
    oxidationState=os;
}

void Element::setSymbol(const QVariant s)
{
    symbol=s;
}

void Element::setCategory(const element_category_t ec)
{
    category=ec;
}
