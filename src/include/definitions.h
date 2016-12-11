#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <QString>
#include <QMap>
#include <QHash>
#include <stdint.h>

#define ELEMENT_TABLE_PATH "../resources/element_list.csv"
#define MIN_ELT_AN          1
#define MAX_ELT_AN          118

enum {
    ELT_LIST_AN=0,
    ELT_LIST_AM=3
};

/*importation_data.h*/
typedef QString Filename;
typedef enum importation_code{
    IC_OK=0,
    IC_ERROR
}importation_code_t;

/*element.h*/
typedef enum element_category{
    EC_ALKALI_METAL=0,
    EC_ALKALINE_EARTH_METAL,
    EC_TRANSITION_METAL,
    EC_METAL_OTHER,
    EC_HYDROGEN,
    EC_SEMICONDUCTOR,
    EC_NOBLE_GAS,
    EC_NON_METAL_OTHER,
    NB_EC_CATEGORIES
}element_category_t;

class Element;

typedef uint8_t AtomicNumber;
typedef QMap<AtomicNumber, Element> ElementsTable;
typedef QList<Element> ElementsList;

/*elementpicker.h*/
/**
  * QHash<AtomicNumber, Quantity of element>
  * */
typedef QHash<uint8_t, uint8_t> RequestedElements;

#endif // DEFINITIONS_H
