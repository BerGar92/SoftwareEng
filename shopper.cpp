//
// Created by realb on 02/12/2023.
//

#include "shopper.h"

void shopper::options() {
    bool loggedIn = true;
    while (loggedIn) {
        cout << "Shopper options" << endl;
        cout << "1. View products" << endl;
        cout << "2. View basket" << endl;
        cout << "3. Update addresses" << endl;
        cout << "4. View past orders" << endl;
        cout << "5. Logout" << endl;
        cout << "Enter option: ";
        int option;
        cin >> option;
        switch (option) {
            case 1:
                view_products(false);
                break;
            case 2:
                modify_basket();
                break;
            case 3:
                modify_addresses();
                break;
            case 4:
                view_orders();
                break;
            case 5:
                cout << "Logging out" << endl;
                loggedIn = false;
                break;
            default:
                cout << "Invalid option" << endl;
                break;
        }
    }
}