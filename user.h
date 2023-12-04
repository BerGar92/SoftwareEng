//
// Created by realb on 02/12/2023.
//

#ifndef SOFTWAREENGV2_USER_H
#define SOFTWAREENGV2_USER_H

#include <string>
#include "address.h"
#include "productItem.h"
#include "basketItem.h"
#include "package.h"

class user {
public:
    user(productItem* firstProduct, string permissionLevel, address* firstAddress);
    virtual ~user() = default;

    void print_addresses();
    void modify_addresses();
    void add_address();
    void remove_address();
    address* get_firstAddress();

    void view_products(bool modifying);
    productItem* get_firstProduct();

    void view_basket();
    void modify_basket();
    void add_to_basket();
    void update_basket();
    void remove_from_basket();
    void set_firstBasketItemNULL();
    double get_basketTotal();
    void checkout();

    void do_delivery();
    void complete_delivery();
    void view_orders();

private:
    address* firstAddress;
    productItem* firstProduct;
    basketItem* firstBasket;
    package* firstLivePackage;
    package* firstCompletedPackage;

    string permissionLevel;
    int noAddresses = 0;

    int deliveryStage;

};


#endif //SOFTWAREENGV2_USER_H
