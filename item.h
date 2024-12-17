#ifndef ITEM_H
#define ITEM_H
#include <QString>

class Item
{
public:
    Item(QString iname, QString iid, double iprice);
    QString getName() const;
    double getPrice() const;
    QString getID() const;
    void setName(QString iname);
    void setPrice(double iprice);
    void setID(QString iid);
    QString toString()const;


private:
    QString id;
    QString name;
    double price;
};

#endif // ITEM_H
