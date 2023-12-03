//
// Created by realb on 03/12/2023.
//

#ifndef SOFTWAREENGV2_PACKAGE_H
#define SOFTWAREENGV2_PACKAGE_H

#include "basketItem.h"

class package {
public:
    package(basketItem* firstBasketItem, address* from, address* to);
    ~package() = default;

    void view_package();
    package* get_nextPackage();
    void set_nextPackage(package* newPackage);

private:
    basketItem* firstBasketItem;
    address* from;
    address* to;
    package* nextPackage;
};


#endif //SOFTWAREENGV2_PACKAGE_H
