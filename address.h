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
    void set_number(int No);

    string get_name();
    void set_name(string name);

    int get_buildingNumber();
    void set_buildingNumber(int buildingNo);

    string get_road();
    void set_road(string street);

    string get_postcode();
    void set_postcode(string zipcode);

    string get_country();
    void set_country(string country);

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
