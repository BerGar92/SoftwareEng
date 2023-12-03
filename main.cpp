#include <iostream>
#include "address.h"
#include "productItem.h"
#include "shopper.h"
#include "admin.h"
using namespace std;

address* createFirstWherehouse();
productItem* createProductList(address* firstWherehouse);

int main() {
    address *firstWherehouse = createFirstWherehouse();
    productItem *firstProduct = createProductList(firstWherehouse);
    admin administator = admin(firstProduct, firstWherehouse);
    shopper buyer = shopper(firstProduct);

    bool running = true;
    int choice;
    do {
        do {
            cout << "Welcome to the login page" << endl;
            cout << "Login as shopper (1)" << endl;
            cout << "Login as admin (2)" << endl;
            cout << "Quit (3)" << endl;
            cin >> choice;
        } while (choice != 1 && choice != 2 && choice != 3);

        if (choice == 1) {
            cout << "You have logged in as a shopper" << endl << endl;
            buyer.options();
            cout << "You have logged out from shopper account" << endl << endl;
        }
        else if (choice == 2) {
            cout << "You have logged in as an admin" << endl;
            administator.options();
            cout << "You have logged out from admin account" << endl << endl;
        }
        else {
            running = false;
        }
        choice = 9;
    } while (running);

    return 0;
}

address* createFirstWherehouse() {
    address *firstWherehouse = new address(1, "London Warehouse", 69, "Baker Street", "NW1 6XE", "England");
    return firstWherehouse;
}

productItem* createProductList(address* firstWherehouse) {
    string catergories[5] = {"Clothes", "Electronics", "Furniture", "Garden", "Stationary"};
    string products[5][5] = {{"T-Shirt", "Jeans", "Jumper", "Shoes", "Socks"},
                             {"Phone", "Laptop", "TV", "Headphones", "Speakers"},
                             {"Table", "Chair", "Bed", "Wardrobe", "Chest of Drawers"},
                             {"Lawnmower", "Hose", "Spade", "Fork", "Rake"},
                             {"Pen", "Pencil", "Paper", "Stapler", "Eraser"}};
    productItem *firstProduct = NULL;
    for (int i = 0; i < 25; i++) {
        productItem *newProduct = new productItem(i+1, products[i/5][i%5], catergories[i/5], firstWherehouse, (rand() % 100), (rand() % 25));
        if (i == 0) {
            firstProduct = newProduct;
        }
        else {
            productItem *currentProduct = firstProduct;
            while (currentProduct->get_nextProduct() != NULL) {
                currentProduct = currentProduct->get_nextProduct();
            }
            currentProduct->set_nextProduct(newProduct);
        }
    }
    return firstProduct;
}