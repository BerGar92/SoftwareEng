//
// Created by realb on 03/12/2023.
//

#include "admin.h"

void admin::options() {
    bool loggedIn = true;
    while (loggedIn) {
        cout << "Admin options" << endl;
        cout << "1. View products" << endl;
        cout << "2. Update products" << endl;
        cout << "3. View basket" << endl;
        cout << "4. Update addresses" << endl;
        cout << "5. View past orders" << endl;
        cout << "6. Logout" << endl;
        cout << "Enter option: ";
        int option;
        cin >> option;
        switch (option) {
            case 1:
                view_products(false);
                break;
            case 2:
                update_products();
                break;
            case 3:
                modify_basket();
                break;
            case 4:
                modify_addresses();
                break;
            case 5:
                view_orders();
                break;
            case 6:
                cout << "Logging out" << endl;
                loggedIn = false;
                break;
            default:
                cout << "Invalid option" << endl;
                break;
        }
    }
}

///Modify products
void admin::update_products() {
    bool updating = true;
    while (updating) {
        cout << "1. Add new product" << endl;
        cout << "2. Restock product" << endl;
        cout << "3. Remove product" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter option: ";
        int option;
        cin >> option;
        switch (option) {
            case 1:
                add_product();
                break;
            case 2:
                restock_product();
                break;
            case 3:
                remove_product();
                break;
            case 4:
                updating = false;
                break;
            default:
                cout << "Invalid option" << endl;
                break;
        }
    }
    cout << endl;
}
void admin::add_product() {
    productItem* currentProduct = get_firstProduct();
    while (currentProduct->get_nextProduct() != NULL) {
        currentProduct = currentProduct->get_nextProduct();
    }
    int productNumber = currentProduct->get_productNumber() + 1;
    string name;
    string catergory;
    double price;
    int amount;
    int location;
    cout << "Enter product name: " << endl;
    cin >> name;
    cout << "Enter product catergory: " << endl;
    cin >> catergory;
    cout << "Enter product price: " << endl;
    cin >> price;
    cout << "Enter product amount: " << endl;
    cin >> amount;
    print_addresses();
    cout << "Enter product address number: " << endl;
    cin >> location;
    address* currentAddress = get_firstAddress();
    while (currentAddress->get_number() != location) {
        currentAddress = currentAddress->get_nextAddress();
        if (currentAddress == NULL) {
            cout << "Invalid address" << endl;
            return;
        }
    }
    productItem* newProduct = new productItem(productNumber, name, catergory, currentAddress, price, amount);
    currentProduct->set_nextProduct(newProduct);
}
void admin::restock_product() {
    view_products(true);
    int productNumber;
    cout << "Enter product number to restock: " << endl;
    cout << "Enter 0 to cancel" << endl;
    cin >> productNumber;
    if (productNumber == 0) return;
    productItem* currentProduct = get_firstProduct();
    while (currentProduct->get_productNumber() != productNumber) {
        currentProduct = currentProduct->get_nextProduct();
        if (currentProduct == NULL) {
            cout << "Invalid product number" << endl;
            return;
        }
    }
    int amount;
    cout << "Enter amount to restock: " << endl;
    cin >> amount;
    currentProduct->set_stockCount(currentProduct->get_stockCount() + amount);
}
void admin::remove_product() {
    view_products(true);
    int productNumber;
    cout << "Enter product number to remove: " << endl;
    cout << "Enter 0 to cancel" << endl;
    cin >> productNumber;
    if (productNumber == 0) return;

    productItem* currentProduct = get_firstProduct();
    productItem* prevProduct = get_firstProduct();
    while (currentProduct->get_productNumber() != productNumber) {
        prevProduct = currentProduct;
        currentProduct = currentProduct->get_nextProduct();
        if (currentProduct == NULL) {
            cout << "Invalid product number" << endl;
            return;
        }
    }
    if (currentProduct->get_stockCount() > 0) {
        cout << "Cannot remove product with stock" << endl;
        return;
    }
    else {
        prevProduct->set_nextProduct(currentProduct->get_nextProduct());
        delete currentProduct;
    }
}