#ifndef ELEMENTPICKER_H
#define ELEMENTPICKER_H

#include "include/definitions.h"
#include "phy/element.h"

class ElementPicker
{
public:
    ElementPicker();
    ~ElementPicker();

    ElementsList pickElementsFromTable(ElementsTable&, const RequestedElements &);

private:
    int isAtomicNumberValid(uint8_t); //0:valid
};

#endif // ELEMENTPICKER_H
