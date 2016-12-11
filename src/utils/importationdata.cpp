#include "importationdata.h"

#include <QFile>
#include <QStringList>
#include <QByteArray>
#include <QDebug>

#include "phy/element.h"
#include "include/definitions.h"

ImportationData::ImportationData()
{
    filename.clear();
}

ImportationData::ImportationData(const Filename & file):filename(file)
{

}

importation_code_t ImportationData::importData(ElementsTable &et)
{
    if(filename.isEmpty())
        return IC_ERROR;

    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return IC_ERROR;

    QTextStream in(&file);
    QStringList strl;
    while(!in.atEnd())
    {
        QString line = in.readLine();

        if(line.isEmpty())
            continue;

        strl=line.split(";");

        uint8_t an=strl.first().toUInt();
        if(et.find(an) == et.end())
        {
            Element elt;
            elt.setAtomicNumber(strl.at(ELT_LIST_AN).toUInt());
            elt.setAtomicMass(strl.at(ELT_LIST_AM).toDouble());
            et.insert(an, elt);
        }
    }
    file.close();

    return IC_OK;
}
