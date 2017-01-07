#include "elementpicker.h"
#include <QDebug>

ElementPicker::ElementPicker()
{

}

ElementPicker::~ElementPicker()
{

}

ElementsList ElementPicker::pickElementsFromTable(ElementsTable & table, const RequestedElements & request)
{
    ElementsList elist;

    if(table.isEmpty() || request.isEmpty())
        return elist;

    RequestedElements::const_iterator itReq = request.begin();

    for(;itReq!=request.end();++itReq)
    {
        uint8_t an=itReq.key();
        if(!isAtomicNumberValid(an))
            continue;

        uint8_t quantityOfElement=itReq.value();

        if(quantityOfElement==0)
            continue;

        ElementsTable::const_iterator itTable=table.begin();
        itTable=table.find(an);
        if(itTable != table.end())
        {
            for(int i=0; i<quantityOfElement;++i)
                elist.append(itTable.value());
        }
    }
    return elist;
}


int ElementPicker::isAtomicNumberValid(uint8_t an)
{
    int valid=0;

    if(an >= MIN_ELT_AN && an <= MAX_ELT_AN)
        valid=1;

    return valid;
}
