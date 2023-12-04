//
// Created by realb on 30/11/2023.
//

#ifndef SOFTWAREENGV2_PRODUCTITEM_H
#define SOFTWAREENGV2_PRODUCTITEM_H

#include <string>
#include "address.h"
using namespace std;

class productItem {
public:
    productItem(int productNumber, string name, string catergory, address* location, int price, int stockCount);
    ~productItem() = default;

    int get_productNumber();

    string get_name();

    address* get_location();

    int get_price();

    int get_stockCount();
    void set_stockCount(int amount);

    productItem* get_nextProduct();
    void set_nextProduct(productItem* newItem);

private:
    int productNumber;
    string name;
    string catergory;
    address* location;
    int price;
    int stockCount;
    productItem* nextProduct;
};


#endif //SOFTWAREENGV2_PRODUCTITEM_H
