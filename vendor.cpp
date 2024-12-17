#include "vendor.h"
#include <QString>

//Default constructor
Vendor::Vendor() :name("Unknown"){}

//Parameterized constructor
Vendor::Vendor(QString vid, QString vname, QString vaddress)
    : id(vid), name(vname), address(vaddress) {}

//Getters
QString Vendor::getID() const {
    return id;
}

QString Vendor::getName() const {
    return name;
}

QString Vendor::getAddress() const {
    return address;
}
//Setters
void Vendor::setID(QString vid) {
    id = id;
}

void Vendor::setName(QString vname) {
    name = vname;
}

void Vendor::setAddress(QString vaddress) {
    address = vaddress;
}

//boof method to check if name is available
bool Vendor::isAvailable() const {
        return !name.isEmpty();
}

//QString t display vendor details
QString Vendor::toString() const {
    return QString("Name of Vendor: %1\nVendor ID: %2\nVendor address: %3").arg(name).arg(id).arg(address);
}
