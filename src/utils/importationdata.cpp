#include "importationdata.h"

#include <QFile>
#include <QStringList>
#include <QByteArray>
#include <QDebug>
#include <QMessageLogger>
#include <errno.h>

#include "phy/element.h"
#include "include/definitions.h"

ImportationData::ImportationData()
{
    filename.clear();
}

ImportationData::ImportationData(const Filename & file):filename(file)
{

}

int ImportationData::importData(ElementsTable &et)
{
    if(filename.isEmpty())
        return -1;

    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qCritical() << "importing file " << filename << ": " << QString(strerror(errno));
        return errno;
    }

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
            elt.setSymbol(QVariant(strl.at(ELT_LIST_SYMB)));
#ifdef VERBOSE
            qDebug() << "element " <<  elt.getSymbol().toString();
#endif
            elt.setAtomicNumber(strl.at(ELT_LIST_AN).toUInt());
            elt.setAtomicMass(strl.at(ELT_LIST_AM).toDouble());
            elt.configureOrbitalSpace();
            et.insert(an, elt);
        }
    }
    file.close();

    return IC_OK;
}
