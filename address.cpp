//
// Created by realb on 02/12/2023.
//

#include "address.h"
#include <iostream>


address::address(int No, string name, int buildingNo, string street, string zipcode, string country) {
    cout << "Creating new address" << endl;
    this->number = No;
    this->name = name;
    this->buildingNumber = buildingNo;
    this->road = street;
    this->postcode = zipcode;
    this->country = country;
    this->nextAddress = NULL;
    cout << "Address number:\t\t\t" << number << endl;
    cout << "Address name:\t\t\t" << name << endl;
    cout << "Address building number:\t" << buildingNumber << endl;
    cout << "Address road:\t\t\t" << road << endl;
    cout << "Address postcode:\t\t" << postcode << endl;
    cout << "Address country:\t\t" << country << endl;
    cout << "Address created" << endl;
}

int address::get_number() {
    return number;
}
void address::set_number(int No) {
    number = No;
}

string address::get_name() {
    return name;
}
void address::set_name(string name) {
    this->name = name;
}

int address::get_buildingNumber() {
    return buildingNumber;
}
void address::set_buildingNumber(int buildingNo) {
    buildingNumber = buildingNo;
}

string address::get_road() {
    return road;
}
void address::set_road(string street) {
    road = street;
}

string address::get_postcode() {
    return postcode;
}
void address::set_postcode(string zipcode) {
    postcode = zipcode;
}

string address::get_country() {
    return country;
}
void address::set_country(string country) {
    this->country = country;
}

address* address::get_nextAddress() {
    return nextAddress;
}
void address::set_nextAddress(address* newAddress) {
    nextAddress = newAddress;
}