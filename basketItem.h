//
// Created by realb on 02/12/2023.
//

#ifndef SOFTWAREENGV2_BASKETITEM_H
#define SOFTWAREENGV2_BASKETITEM_H

#include <string>
#include <iostream>
#include "productItem.h"
using namespace std;

class basketItem {
public:
    basketItem(productItem* product, int quantity);
    ~basketItem() = default;

    productItem* get_product();
    address* get_location();

    int get_quantity();
    void set_quantity(int quantity);

    basketItem* get_nextItem();
    void set_nextItem(basketItem* newItem);

private:
    productItem* product;
    int quantity;
    basketItem* nextItem;
};


#endif //SOFTWAREENGV2_BASKETITEM_H
