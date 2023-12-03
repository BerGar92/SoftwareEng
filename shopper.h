//
// Created by realb on 02/12/2023.
//

#ifndef SOFTWAREENGV2_SHOPPER_H
#define SOFTWAREENGV2_SHOPPER_H

#include "user.h"

class shopper : public user {
public:
    shopper(productItem* firstProduct) : user(firstProduct, "shopper", NULL) {
        cout << "Creating new shopper" << endl;
        cout << "Shopper created" << endl;};
    ~shopper() = default;

    void options();

private:

};


#endif //SOFTWAREENGV2_SHOPPER_H
