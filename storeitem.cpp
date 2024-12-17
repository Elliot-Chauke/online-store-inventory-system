#include "storeitem.h"
#include "item.h"
#include <QString>

//Constructor for StoreItem and initialize base class
StoreItem::StoreItem(QString iname, QString iid, double iprice, Vendor* vendor)
    : Item(iname, iid, iprice), hasVendor(vendor != 0) {}

//Set the vendor for StoreItem
void StoreItem::setVendor(const Vendor* vendor)
{
    if (vendor) {
        svendor = *vendor;
        hasVendor = true;
    } else {
        svendor = Vendor();
        hasVendor = false;
    }
}

//Return vendor name or return "Unknown" if not available
QString StoreItem::getVendorName() const {
    if(svendor.isAvailable())
    {
        return svendor.getName();
    }
    else
    {
        return "Unknown";
    }


}

//QString to display StoreItem details
QString StoreItem::toString(bool vendorDetails) const {
    QString itemDetails = Item::toString();
    if (vendorDetails && hasVendor) {
        return itemDetails +"\n" + svendor.toString();
    }
    else
    {
    return itemDetails;
    }
}
