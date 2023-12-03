//
// Created by realb on 02/12/2023.
//

#include "basketItem.h"

basketItem::basketItem(productItem* product, int quantity) {
    cout << "Creating new basket item" << endl;
    this->product = product;
    this->quantity = quantity;
    this->nextItem = NULL;
    cout << "Basket item product:\t" << product->get_name() << endl;
    cout << "Basket item quantity:\t" << quantity << endl;
    cout << "Basket item created" << endl;
}

productItem* basketItem::get_product() {
    return this->product;
}
void basketItem::set_product(productItem* product) {
    this->product = product;
}
address* basketItem::get_location() {
    return this->product->get_location();
}

int basketItem::get_quantity() {
    return this->quantity;
}
void basketItem::set_quantity(int quantity) {
    this->quantity = quantity;
}

basketItem* basketItem::get_nextItem() {
    return this->nextItem;
}
void basketItem::set_nextItem(basketItem* newItem) {
    this->nextItem = newItem;
}
