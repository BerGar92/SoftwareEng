//
// Created by realb on 03/12/2023.
//

#ifndef SOFTWAREENGV2_ADMIN_H
#define SOFTWAREENGV2_ADMIN_H

#include "user.h"

class admin : public user{
public:
    admin(productItem* firstProduct, address* firstAddress) : user(firstProduct, "admin", firstAddress) {
        cout << "Creating new admin" << endl;
        cout << "Admin created" << endl;};
    ~admin() = default;

    void options();

    void update_products();
    void add_product();
    void restock_product();
    void remove_product();
};


#endif //SOFTWAREENGV2_ADMIN_H
