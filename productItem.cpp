//
// Created by realb on 30/11/2023.
//

#include "productItem.h"
#include <iostream>
using namespace std;

productItem::productItem(int productNumber, string name, string catergory, address* location, int price, int stockCount) {
    cout << "Creating new product"<< endl;
    this->productNumber = productNumber;
    this->name = name;
    this->catergory = catergory;
    this->location = location;
    this->price = price;
    this->stockCount = stockCount;
    this->nextProduct = NULL;
    cout << "New product created"<< endl;
    cout << "Product number:\t\t" << this->productNumber << endl;
    cout << "Product name:\t\t" << this->name << endl;
    cout << "Product catergory:\t" << this->catergory << endl;
    cout << "Product location:\t" << this->location->get_name() << endl;
    cout << "Product price:\t\t" << this->price << endl;
    cout << "Product stock count:\t" << this->stockCount << endl;
}

int productItem::get_productNumber() {
    return this->productNumber;
}
void productItem::set_productNumber(int no) {
    this->productNumber = no;
}

string productItem::get_name() {
    return this->name;
}
void productItem::set_name(string name) {
    this->name = name;
}

string productItem::get_catergory() {
    return this->catergory;
}
void productItem::set_catergory(string cat) {
    this->catergory = cat;
}

address* productItem::get_location() {
    return this->location;
}
string productItem::get_locationName() {
    return this->location->get_name();
}
void productItem::set_location(address* loc) {
    this->location = loc;
}

int productItem::get_price() {
    return this->price;
}
void productItem::set_price(int cost) {
    this->price = cost;
}

int productItem::get_stockCount() {
    return this->stockCount;
}
void productItem::set_stockCount(int amount) {
    this->stockCount = amount;
}

productItem* productItem::get_nextProduct() {
    return this->nextProduct;
}
void productItem::set_nextProduct(productItem* newItem) {
    this->nextProduct = newItem;
}