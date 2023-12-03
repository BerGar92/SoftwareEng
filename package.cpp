//
// Created by realb on 03/12/2023.
//

#include "package.h"

package::package(basketItem* firstBasketItem, address* from, address* to) {
    this->firstBasketItem = firstBasketItem;
    this->from = from;
    this->to = to;
    this->nextPackage = NULL;
}

void package::view_package() {
    basketItem* currentBasketItem = firstBasketItem;
    productItem *currentProduct = NULL;
    while (currentBasketItem != NULL) {
        currentProduct = currentBasketItem->get_product();
        cout << "Product number:\t" << currentProduct->get_productNumber() << endl;
        cout << "Product name:\t" << currentProduct->get_name() << endl;
        cout << "Product price:\t" << currentProduct->get_price() << endl;
        cout << "Product amount:\t" << currentBasketItem->get_quantity() << endl;
        cout << "Total cost:\t" << currentBasketItem->get_quantity() * currentProduct->get_price() << endl;
        cout << endl;
        currentBasketItem = currentBasketItem->get_nextItem();
    }
    cout << "From: " << from->get_name() << endl;
    cout << "To: " << to->get_name() << endl << endl;
}

package* package::get_nextPackage() {
    return nextPackage;
}
void package::set_nextPackage(package* newPackage) {
    nextPackage = newPackage;
}