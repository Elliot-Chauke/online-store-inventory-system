#ifndef STOREITEM_H
#define STOREITEM_H
#include "item.h"
#include "vendor.h"

class StoreItem : public Item {
public:
   StoreItem(QString iname, QString iid, double iprice, Vendor* vendor = 0);
    void setVendor(const Vendor *vendor);
    QString getVendorName() const;
    QString toString(bool vendorDetails = false) const;

private:
    Vendor svendor;
    bool hasVendor;
};

#endif // STOREITEM_H
