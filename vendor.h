#ifndef VENDOR_H
#define VENDOR_H
#include <QString>

class Vendor
{
public:
    Vendor();
    Vendor(QString vid, QString vname, QString vaddress);
    QString getID() const;
    QString getName() const;
    QString getAddress() const;
    void setID(QString vid);
    void setName(QString vname);
    void setAddress(QString vaddress);
     bool isAvailable() const;
    QString toString() const;


private:
    QString id;
    QString name;
    QString address;
};

#endif // VENDOR_H
