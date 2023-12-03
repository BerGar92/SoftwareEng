//
// Created by realb on 02/12/2023.
//

#include "user.h"

user::user(productItem* firstProduct, string permissionLevel, address* firstAddress) {
    this->firstAddress = firstAddress;
    this->firstProduct = firstProduct;
    this->firstBasket = NULL;
    this->permissionLevel = permissionLevel;
    this->firstLivePackage = NULL;
    this->firstCompletedPackage = NULL;
    cout << endl;
}

///Address functions
void user::print_addresses() {
    address* currentAddress = firstAddress;
    if (currentAddress == NULL) {
        cout << "No addresses to show" << endl << endl;
        return;
    }
    else {
        while (currentAddress != NULL) {
            cout << "Address number:\t" << currentAddress->get_number() << endl;
            cout << "Address name:\t" << currentAddress->get_name() << endl;
            cout << "Building no.:\t" << currentAddress->get_buildingNumber() << endl;
            cout << "Street:\t" << currentAddress->get_road() << endl;
            cout << "Postcode: " << currentAddress->get_postcode() << endl;
            cout << "Country: " << currentAddress->get_country() << endl;
            cout << endl;
            currentAddress = currentAddress->get_nextAddress();
        }
    }
}
void user::modify_addresses() {
    print_addresses();
    bool modifying = true;
    while (modifying) {
        int choice;
        cout << "1. Add address" << endl;
        cout << "2. Remove address" << endl;
        cout << "3. Return to previous menu" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cout << endl;
        switch (choice) {
            case 1:
                add_address();
                break;
            case 2:
                remove_address();
                break;
            case 3:
                modifying = false;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }

}
void user::add_address() {
    string name;
    int buildingNumber;
    string road;
    string postcode;
    string country;

    cout << "Enter address name: ";
    cin >> name;
    cout << "Enter building number: ";
    cin >> buildingNumber;
    cout << "Enter road name: ";
    cin >> road;
    cout << "Enter postcode: ";
    cin >> postcode;
    cout << "Enter country: ";
    cin >> country;

    address* newAddress = new address(++noAddresses, name, buildingNumber, road, postcode, country);
    if (firstAddress == NULL) {
        firstAddress = newAddress;
    }
    else {
        address* currentAddress = firstAddress;
        while (currentAddress->get_nextAddress() != NULL) {
            currentAddress = currentAddress->get_nextAddress();
        }
        currentAddress->set_nextAddress(newAddress);
    }
}
void user::remove_address() {
    print_addresses();
    int addressNo;
    cout << "Enter address number to remove:" << endl;
    if(permissionLevel == "admin") cout << "Original wherehouse cannot be removed" << endl;
    cout << "If you want to cancel enter 0" << endl << endl;
    cin >> addressNo;

    if (addressNo == 0) return;
    if (addressNo == 1 && permissionLevel == "admin") return;
    address *currentAddress = firstAddress;
    int count;
    while (currentAddress->get_number() != addressNo) {
        if (currentAddress->get_nextAddress() == NULL) {
            cout << "Address not found" << endl;
            return;
        }
        else {
            currentAddress = currentAddress->get_nextAddress();
            count++;
        }
    }

    char choice;
    bool validInput = false;
    do {
        cout << "Are you sure you want to remove " << currentAddress->get_name() << " permanently?" << endl;
        cout << "[y/n]" << endl;
        cin >> choice;
        if (choice == 'y' || choice == 'n') validInput = true;
    } while (!validInput);

    if (choice == 'y') {
        address *temp;
        temp = currentAddress->get_nextAddress();
        address *prevAddress = firstAddress;
        for (int i = 0; i < (count); i++) {
            if (prevAddress->get_nextAddress() == NULL) break;
            else {
                prevAddress = prevAddress->get_nextAddress();
            }
        }
        prevAddress->set_nextAddress(temp);
        delete currentAddress;
        noAddresses--;
    }
    else return;
}
address* user::get_firstAddress() {
    return firstAddress;
}

///Product functions
void user::view_products(bool modifying) {
    productItem* currentProduct = firstProduct;
    while (currentProduct != NULL) {
        cout << "Product number:\t" << currentProduct->get_productNumber() << endl;
        cout << "Product name:\t" << currentProduct->get_name() << endl;
        cout << "Product price:\t" << currentProduct->get_price() << endl;
        cout << "Product amount:\t" << currentProduct->get_stockCount() << endl;
        cout << endl;
        currentProduct = currentProduct->get_nextProduct();
    }
    if (!modifying) {
        bool viewing = true;
        while (viewing) {
            int choice;
            cout << "1. Add product to basket" << endl;
            cout << "2. Return to previous menu" << endl;
            cout << "Enter choice: ";
            cin >> choice;
            cout << endl;
            switch (choice) {
                case 1:
                    add_to_basket();
                    break;
                case 2:
                    viewing = false;
                    break;
                default:
                    cout << "Invalid choice" << endl;
                    break;
            }
        }
    }
}
productItem* user::get_firstProduct() {
    return firstProduct;
}

///Basket functions
void user::view_basket() {
    basketItem* currentBasketItem = firstBasket;
    productItem *currentProduct = NULL;
    double totalCost = 0;
    while (currentBasketItem != NULL) {
        currentProduct = currentBasketItem->get_product();
        cout << "Product number:\t" << currentProduct->get_productNumber() << endl;
        cout << "Product name:\t" << currentProduct->get_name() << endl;
        cout << "Product price:\t" << currentProduct->get_price() << endl;
        cout << "Product amount:\t" << currentBasketItem->get_quantity() << endl;
        cout << "Total item cost:\t" << currentBasketItem->get_quantity() * currentProduct->get_price() << endl;
        totalCost += currentBasketItem->get_quantity() * currentProduct->get_price();
        cout << endl;
        currentBasketItem = currentBasketItem->get_nextItem();
    }
    cout << "Total basket cost:\t" << totalCost << endl << endl;
}
void user::modify_basket() {
    if (firstBasket == NULL) {
        cout << "Basket is empty" << endl;
        return;
    }
    else {
        view_basket();
        bool modifying = true;
        while (modifying) {
            int choice;
            cout << "1. Update product amount" << endl;
            cout << "2. Remove product from basket" << endl;
            cout << "3. Checkout" << endl;
            cout << "4. Return to previous menu" << endl;
            cout << "Enter choice: ";
            cin >> choice;
            cout << endl;
            switch (choice) {
                case 1:
                    update_basket();
                    break;
                case 2:
                    remove_from_basket();
                    break;
                case 3:
                    checkout();
                    modifying = false;
                    break;
                case 4:
                    modifying = false;
                    break;
                default:
                    cout << "Invalid choice" << endl;
                    break;
            }
        }
    }
}
void user::add_to_basket() {
    int productNo;
    cout << "Enter product number to add to basket:" << endl;
    cout << "If you want to cancel enter 0" << endl;
    cin >> productNo;

    if (productNo == 0) return;
    productItem* currentProduct = firstProduct;
    while (currentProduct->get_productNumber() != productNo) {
        currentProduct = currentProduct->get_nextProduct();
    }

    address* itemLocation = currentProduct->get_location();
    bool sameLocation = true;
    if (firstBasket != NULL) {
        address* basketLocation = firstBasket->get_location();
        if (itemLocation != basketLocation) {
            cout << "Only order products from one location at a time please" << endl;
            sameLocation = false;
        }
    }
    if (sameLocation) {
        int quantity;
        cout << "Enter quantity: ";
        cin >> quantity;

        basketItem* newBasketItem = new basketItem(currentProduct, quantity);
        if (firstBasket == NULL) {
            firstBasket = newBasketItem;
        }
        else {
            basketItem* currentBasketItem = firstBasket;
            while (currentBasketItem->get_nextItem() != NULL) {
                currentBasketItem = currentBasketItem->get_nextItem();
            }
            currentBasketItem->set_nextItem(newBasketItem);
        }
    }
}

void user::update_basket() {
    view_basket();
    int productNo;
    cout << "Enter product number to update:" << endl;
    cin >> productNo;

    basketItem* currentBasketItem = firstBasket;
    while (currentBasketItem->get_product()->get_productNumber() != productNo) {
        currentBasketItem = currentBasketItem->get_nextItem();
    }

    int quantity;
    cout << "Enter new quantity: ";
    cin >> quantity;
    currentBasketItem->set_quantity(quantity);
}
void user::remove_from_basket() {
    view_basket();
    int productNo;
    cout << "Enter product number to remove:" << endl;
    cout << "If you want to cancel enter 0" << endl;
    cin >> productNo;

    if (productNo == 0) return;

    basketItem* currentBasketItem = firstBasket;
    int count;
    while (currentBasketItem->get_product()->get_productNumber() != productNo) {
        if (currentBasketItem->get_nextItem() == NULL) {
            cout << "Product not found" << endl;
            return;
        }
        else {
            currentBasketItem = currentBasketItem->get_nextItem();
            count++;
        }
    }

    char choice;
    bool validInput = false;
    do {
        cout << "Are you sure you want to remove " << currentBasketItem->get_product()->get_name() << " permanently?" << endl;
        cout << "[y/n]" << endl;
        cin >> choice;
        if (choice == 'y' || choice == 'n') validInput = true;
    } while (!validInput);

    if (choice == 'y') {
        basketItem *temp;
        temp = currentBasketItem->get_nextItem();
        basketItem *prevBasketItem = firstBasket;

        for (int i = 0; i < (count); i++) {
            if (prevBasketItem->get_nextItem() == NULL) break;
            else {
                prevBasketItem = prevBasketItem->get_nextItem();
            }
        }

        if (temp == NULL) set_firstBasketItemNULL();
        else prevBasketItem->set_nextItem(temp);

        delete temp;
        delete currentBasketItem;
    }
    else return;
}
void user::set_firstBasketItemNULL() {
    firstBasket = NULL;
}
double user::get_basketTotal() {
    double total = 0;
    basketItem* currentBasketItem = firstBasket;
    while (currentBasketItem != NULL) {
        total += currentBasketItem->get_quantity() * currentBasketItem->get_product()->get_price();
        currentBasketItem = currentBasketItem->get_nextItem();
    }
    return total;
}
void user::checkout() {
    view_basket();

    char choice;
    cout << "Are you sure you want to checkout?" << endl;
    cout << "[y/n]" << endl;
    cin >> choice;
    if (choice == 'y') {
        ///Select delivery address
        address* deliveryAddress = NULL;
        if (firstAddress == NULL) {
            cout << "Enter delivery address" << endl;
            add_address();
        }
        else {
            print_addresses();
            choice = 'o';
            cout << "Do you want to enter a new delivery address? [y/n]" << endl;
            cin >> choice;
            if (choice == 'y') {
                add_address();
                print_addresses();
            }

            cout << "Enter delivery address number" << endl;
            int addressNo;
            cin >> addressNo;
            address* currentAddress = firstAddress;
            while (currentAddress->get_number() != addressNo) {
                currentAddress = currentAddress->get_nextAddress();
                if (currentAddress == NULL) {
                    cout << "Invalid address" << endl;
                    return;
                }
            }
            deliveryAddress = currentAddress;
        }

        int total = get_basketTotal();
        address* from = firstBasket->get_location();
        if (from->get_country() == deliveryAddress->get_country()) {
            if (total > 50) {
                cout << "Delivery is free" << endl;
            }
            else {
                cout << "Delivery is £" << total * 0.05 << endl;
                total += total * 0.05;
            }
            deliveryStage = 3;
        }
        else {
            cout << "Delivery is " << total * 0.1 << endl;
            total += total * 0.1;
            deliveryStage = 0;
        }
        cout << "Total cost is " << total << endl;

        basketItem* currentBasketItem = firstBasket;
        while (currentBasketItem != NULL) {
            productItem* currentProduct = currentBasketItem->get_product();
            currentProduct->set_stockCount(currentProduct->get_stockCount() - currentBasketItem->get_quantity());
            currentBasketItem = currentBasketItem->get_nextItem();
        }

        ///Create package
        package* newPackage = new package(firstBasket, from, deliveryAddress);
        firstLivePackage = newPackage;
        set_firstBasketItemNULL();

        ///Run through delivery
        do_delivery();
    }
    else return;
}

///Delivery functions
void user::do_delivery() {
    if (deliveryStage == 5) {
        cout << "Delivery complete" << endl;
        complete_delivery();
    }
    else deliveryStage++;
}
void user::complete_delivery() {
    if (firstCompletedPackage == NULL) {
        firstCompletedPackage = firstLivePackage;
        firstLivePackage = NULL;
    }
    else {
        package* currentPackage = firstCompletedPackage;
        while (currentPackage != NULL) {
            currentPackage->view_package();
            currentPackage = currentPackage->get_nextPackage();
        }
        currentPackage = firstLivePackage;
        firstLivePackage = NULL;
    }
}
void user::view_orders() {
    package* currentPackage = firstCompletedPackage;
    while (currentPackage != NULL) {
        currentPackage->view_package();
        currentPackage = currentPackage->get_nextPackage();
    }
}