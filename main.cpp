#include <iostream>
#include "address.h"
#include "productItem.h"
#include "shopper.h"
#include "admin.h"
using namespace std;

//address* createFirstWherehouse();
//productItem* createProductList(address* firstWherehouse);

//Create unit test for 'user' class
#define BOOST_TEST_MODULE UserTests
#include <boost/test/included/unit_test.hpp>

#include "user.h"

BOOST_AUTO_TEST_CASE(test_user_addresses) {
    // Create a sample product list and address
    productItem *firstProduct = new productItem(1, "SampleProduct", "SampleCategory", nullptr, 10, 5);
    address *firstAddress = new address(1, "SampleAddress", 123, "SampleStreet", "12345", "SampleCountry");

    // Create a user with the sample product list and address
    user testUser(firstProduct, "normal", firstAddress);

    // Test address-related functions
    BOOST_CHECK_NO_THROW(testUser.print_addresses());
    BOOST_CHECK_NO_THROW(testUser.modify_addresses());
    BOOST_CHECK_NO_THROW(testUser.add_address());
    BOOST_CHECK_NO_THROW(testUser.remove_address());
    BOOST_CHECK(testUser.get_firstAddress() != nullptr);

    // Clean up
    delete firstProduct;
    delete firstAddress;
}

BOOST_AUTO_TEST_CASE(test_user_products) {
    // Create a sample product list and address
    productItem *firstProduct = new productItem(1, "SampleProduct", "SampleCategory", nullptr, 10, 5);
    address *firstAddress = new address(1, "SampleAddress", 123, "SampleStreet", "12345", "SampleCountry");

    // Create a user with the sample product list and address
    user testUser(firstProduct, "normal", firstAddress);

    // Test product-related functions
    BOOST_CHECK_NO_THROW(testUser.view_products(true));
    BOOST_CHECK(testUser.get_firstProduct() != nullptr);

    // Clean up
    delete firstProduct;
    delete firstAddress;
}

BOOST_AUTO_TEST_CASE(test_user_basket) {
    // Create a sample product list and address
    productItem *firstProduct = new productItem(1, "SampleProduct", "SampleCategory", nullptr, 10, 5);
    address *firstAddress = new address(1, "SampleAddress", 123, "SampleStreet", "12345", "SampleCountry");

    // Create a user with the sample product list and address
    user testUser(firstProduct, "normal", firstAddress);

    // Test basket-related functions
    BOOST_CHECK_NO_THROW(testUser.view_basket());
    BOOST_CHECK_NO_THROW(testUser.modify_basket());
    BOOST_CHECK_NO_THROW(testUser.add_to_basket());
    BOOST_CHECK_NO_THROW(testUser.update_basket());
    BOOST_CHECK_NO_THROW(testUser.remove_from_basket());
    BOOST_CHECK_NO_THROW(testUser.set_firstBasketItemNULL());
    BOOST_CHECK_NO_THROW(testUser.get_basketTotal());
    BOOST_CHECK_NO_THROW(testUser.checkout());

    // Clean up
    delete firstProduct;
    delete firstAddress;
}

BOOST_AUTO_TEST_CASE(test_user_delivery) {
    // Create a sample product list and address
    productItem *firstProduct = new productItem(1, "SampleProduct", "SampleCategory", nullptr, 10, 5);
    address *firstAddress = new address(1, "SampleAddress", 123, "SampleStreet", "12345", "SampleCountry");

    // Create a user with the sample product list and address
    user testUser(firstProduct, "normal", firstAddress);

    // Test delivery-related functions
    BOOST_CHECK_NO_THROW(testUser.do_delivery());
    BOOST_CHECK_NO_THROW(testUser.complete_delivery());
    BOOST_CHECK_NO_THROW(testUser.view_orders());

    // Clean up
    delete firstProduct;
    delete firstAddress;
}


// int main() {
//     address *firstWherehouse = createFirstWherehouse();
//     productItem *firstProduct = createProductList(firstWherehouse);
//     admin administator = admin(firstProduct, firstWherehouse);
//     shopper buyer = shopper(firstProduct);

//     bool running = true;
//     int choice;
//     do {
//         do {
//             cout << "Welcome to the login page" << endl;
//             cout << "Login as shopper (1)" << endl;
//             cout << "Login as admin (2)" << endl;
//             cout << "Quit (3)" << endl;
//             cin >> choice;
//         } while (choice != 1 && choice != 2 && choice != 3);

//         if (choice == 1) {
//             cout << "You have logged in as a shopper" << endl << endl;
//             buyer.options();
//             cout << "You have logged out from shopper account" << endl << endl;
//         }
//         else if (choice == 2) {
//             cout << "You have logged in as an admin" << endl;
//             administator.options();
//             cout << "You have logged out from admin account" << endl << endl;
//         }
//         else {
//             running = false;
//         }
//         choice = 9;
//     } while (running);

//     return 0;
// }

// address* createFirstWherehouse() {
//     address *firstWherehouse = new address(1, "London Warehouse", 69, "Baker Street", "NW1 6XE", "England");
//     return firstWherehouse;
// }

// productItem* createProductList(address* firstWherehouse) {
//     string catergories[5] = {"Clothes", "Electronics", "Furniture", "Garden", "Stationary"};
//     string products[5][5] = {{"T-Shirt", "Jeans", "Jumper", "Shoes", "Socks"},
//                              {"Phone", "Laptop", "TV", "Headphones", "Speakers"},
//                              {"Table", "Chair", "Bed", "Wardrobe", "Chest of Drawers"},
//                              {"Lawnmower", "Hose", "Spade", "Fork", "Rake"},
//                              {"Pen", "Pencil", "Paper", "Stapler", "Eraser"}};
//     productItem *firstProduct = NULL;
//     for (int i = 0; i < 25; i++) {
//         productItem *newProduct = new productItem(i+1, products[i/5][i%5], catergories[i/5], firstWherehouse, (rand() % 100), (rand() % 25));
//         if (i == 0) {
//             firstProduct = newProduct;
//         }
//         else {
//             productItem *currentProduct = firstProduct;
//             while (currentProduct->get_nextProduct() != NULL) {
//                 currentProduct = currentProduct->get_nextProduct();
//             }
//             currentProduct->set_nextProduct(newProduct);
//         }
//     }
//     return firstProduct;
// }

//Create unit test for 'shopper' class
#define BOOST_TEST_MODULE ShopperTests
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_shopper_options) {
    // Create a sample product list
    productItem *firstProduct = new productItem(1, "SampleProduct", "SampleCategory", nullptr, 10, 5);

    // Create a shopper with the sample product list
    shopper testShopper(firstProduct);

    // Redirect cin to provide input to the shopper's options function
    std::istringstream input("1\n");  // Assuming option 1 is a valid option in the options function

    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());
    BOOST_CHECK_NO_THROW(testShopper.options());  // Check if the function runs without exceptions
    std::cin.rdbuf(oldCin);  // Restore cin

    // Clean up the dynamically allocated memory
    delete firstProduct;
}


BOOST_AUTO_TEST_SUITE_END()
