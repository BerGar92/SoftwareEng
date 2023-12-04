//
// Created by realb on 02/12/2023.
//

#ifndef SOFTWAREENGV2_ADDRESS_H
#define SOFTWAREENGV2_ADDRESS_H

#include <string>
using namespace std;

class address {
public:
     address(int No, string name, int buildingNo, string street, string zipcode, string country);
     ~address() = default;

    int get_number();

    string get_name();

    int get_buildingNumber();

    string get_road();

    string get_postcode();

    string get_country();

    address* get_nextAddress();
    void set_nextAddress(address* newAddress);

private:
    int number;
    string name;
    int buildingNumber;
    string road;
    string postcode;
    string country;
    address* nextAddress;
};


#endif //SOFTWAREENGV2_ADDRESS_H
