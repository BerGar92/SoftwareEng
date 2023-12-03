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
    void set_productNumber(int no);

    string get_name();
    void set_name(string name);

    string get_catergory();
    void set_catergory(string cat);

    address* get_location();
    string get_locationName();
    void set_location(address* loc);

    int get_price();
    void set_price(int cost);

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
