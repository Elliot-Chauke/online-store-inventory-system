#include "item.h"
#include <QString>
#include <QTextStream>

//Constructor
Item::Item(QString iname, QString iid, double iprice)
    : name(iname), id(iid), price(iprice)
{}
//Getters
QString Item::getID()const
{
    return id;
}

QString Item::getName()const
{
    return name;
}

double Item::getPrice()const
{
    return price;
}
//Setters
void Item::setID(QString iid)
{
    id=iid;
}

void Item::setPrice(double iprice)
{
    price=iprice;
}

void Item::setName(QString iname)
{
   name=iname;
}
//QString to display items
 QString Item::toString() const
{

   return QString("Name of Item: %1\nItem ID: %2\nItem price: %3").arg(name).arg(id).arg(QString::number(price, 'f', 2));

}

