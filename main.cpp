#include <QCoreApplication>
#include <QTextStream>
#include "storeitem.h"
#include "vendor.h"
#include <QRegularExpression>

int main() {
    QTextStream cin(stdin);
    QTextStream cout(stdout);
    QRegularExpression intRegex("^[0-9]+$");
    QList<StoreItem*> storeItems;


    int numItems;
    QString numInput;

    //Ask the user to enter a number
    cout << "Enter the number of items: ";
    cout.flush();
    numInput = cin.readLine();

    //Display error message if a correct number is not provided
    if (!intRegex.match(numInput).hasMatch())
    {
       cout << "Invalid. Please enter a valid number." << endl;
       cout << "Enter the number of items: ";
       cout.flush();
       numInput = cin.readLine();
    }
      numItems = numInput.toInt();

    //For loop to loop the number of times provided
    for (int i = 0; i < numItems; ++i) {
        QRegularExpression doubleRegex("^[0-9]+(\\.[0-9]+)?$");
        QString name;
        QString id;
        double price;
        QString vendorName;
        QString vendorAddress;
        QString vendorId;
        QString priceInput;

        //Ask user to enter Item details
        cout << "Item details" << endl;
        cout << "Enter item " << i + 1 << " Name: ";
        cout.flush();
        name = cin.readLine();

        cout << "Enter item " << i + 1 << " ID(numbers and letters): ";
        cout.flush();
        cin >> id;
        cin.readLine();

        cout << "Enter item " << i + 1 << " Price: ";
        cout.flush();
        cin >> priceInput;
        cin.readLine();

        //Display error message if a valid number is not provided
        if (!doubleRegex.match(priceInput).hasMatch())
        {
           cout << "Invalid. Please enter a valid number." << endl;
           cout << "Enter item " << i + 1 << " Price: ";
           cout.flush();
           cin >> priceInput;
           cin.readLine();
        }
        price = priceInput.toInt();
        cout << endl;


        //Ask the user to enter Vendor details
        cout << "Vendor details" << endl;
        cout << "Enter vendor " << i + 1 << " Name: ";
        cout.flush();
        vendorName = cin.readLine();

        cout << "Enter vendor " << i + 1 << " ID(numbers and letters): ";
        cout.flush();
        vendorId = cin.readLine();


        cout << "Enter vendor " << i + 1 << " Address: ";
        cout.flush();
        vendorAddress = cin.readLine();
        cout << endl;

        //Vendor and StoreItems objects
        Vendor* vendor = new Vendor(vendorId, vendorName, vendorAddress);
        StoreItem* storeItem = new StoreItem(name, id, price);
        Vendor* vendorPtr = vendor;
        storeItem->setVendor(vendorPtr);

        storeItems.append(storeItem);
    }

    //For loop to display Item details without vendor details
    cout << "\nItem details without vendor details: " << endl;
    cout << "-------------------------------------- " << endl;
    for (int i = 0; i < storeItems.size(); ++i) {
        StoreItem* item = storeItems[i];
        cout << item->toString(false) <<endl;
        cout.flush();
    }

    //For loop to display Item details with vendor details
    cout << "\n\nItem details with vendor details: " <<endl;
    cout << "------------------------------------- " <<endl;
    for (int i = 0; i < storeItems.size(); ++i) {
        StoreItem* item = storeItems.at(i);
        cout << item->toString(true) <<endl;
        cout.flush();
    }

    //For loop to display ite name and their vendor
    cout << "\nVendor names for each item: " << endl;
    cout << "----------------------------- " << endl;
    for (int i = 0; i < storeItems.size(); ++i) {
        StoreItem* item = storeItems.at(i);
        cout << "Vendor name for item " << item->getName() << ": " << item->getVendorName() << "\n";
        cout.flush();

    }

    //Cleans dynamically allocated memory
    qDeleteAll(storeItems);
    storeItems.clear();

    return 0;
}
