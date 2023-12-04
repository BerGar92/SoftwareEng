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

// Set Up Unit Test for 'admin' class
#define BOOST_TEST_MODULE AdminTests

BOOST_AUTO_TEST_CASE(test_admin_options) {
    // Create a sample product list and address
    productItem *firstProduct = new productItem(1, "SampleProduct", "SampleCategory", nullptr, 10, 5);
    address *firstAddress = new address(1, "SampleAddress", 123, "SampleStreet", "12345", "SampleCountry");

    // Create an admin with the sample product list and address
    admin testAdmin(firstProduct, firstAddress);

    // Test admin options
    BOOST_CHECK_NO_THROW(testAdmin.options());

    // Clean up
    delete firstProduct;
    delete firstAddress;
}

BOOST_AUTO_TEST_CASE(test_admin_product_modification) {
    // Create a sample product list and address
    productItem *firstProduct = new productItem(1, "SampleProduct", "SampleCategory", nullptr, 10, 5);
    address *firstAddress = new address(1, "SampleAddress", 123, "SampleStreet", "12345", "SampleCountry");

    // Create an admin with the sample product list and address
    admin testAdmin(firstProduct, firstAddress);

    // Test admin product modification functions
    BOOST_CHECK_NO_THROW(testAdmin.update_products());
    BOOST_CHECK_NO_THROW(testAdmin.add_product());
    BOOST_CHECK_NO_THROW(testAdmin.restock_product());
    BOOST_CHECK_NO_THROW(testAdmin.remove_product());

    // Clean up
    delete firstProduct;
    delete firstAddress;
}

//Set up unit test for 'address' class
#define BOOST_TEST_MODULE AddressTests

BOOST_AUTO_TEST_CASE(test_address_getters_and_setters) {
    // Create an address
    address testAddress(1, "SampleAddress", 123, "SampleStreet", "12345", "SampleCountry");

    // Test getters
    BOOST_CHECK_EQUAL(testAddress.get_number(), 1);
    BOOST_CHECK_EQUAL(testAddress.get_name(), "SampleAddress");
    BOOST_CHECK_EQUAL(testAddress.get_buildingNumber(), 123);
    BOOST_CHECK_EQUAL(testAddress.get_road(), "SampleStreet");
    BOOST_CHECK_EQUAL(testAddress.get_postcode(), "12345");
    BOOST_CHECK_EQUAL(testAddress.get_country(), "SampleCountry");
    BOOST_CHECK(testAddress.get_nextAddress() == nullptr);

    // Test setters
    testAddress.set_number(2);
    BOOST_CHECK_EQUAL(testAddress.get_number(), 2);

    testAddress.set_name("UpdatedAddress");
    BOOST_CHECK_EQUAL(testAddress.get_name(), "UpdatedAddress");

    testAddress.set_buildingNumber(456);
    BOOST_CHECK_EQUAL(testAddress.get_buildingNumber(), 456);

    testAddress.set_road("UpdatedStreet");
    BOOST_CHECK_EQUAL(testAddress.get_road(), "UpdatedStreet");

    testAddress.set_postcode("54321");
    BOOST_CHECK_EQUAL(testAddress.get_postcode(), "54321");

    testAddress.set_country("UpdatedCountry");
    BOOST_CHECK_EQUAL(testAddress.get_country(), "UpdatedCountry");

    // Clean up
    // Destructor is automatically called when the testAddress goes out of scope
}

BOOST_AUTO_TEST_CASE(test_address_next_address) {
    // Create two addresses
    address firstAddress(1, "FirstAddress", 123, "FirstStreet", "11111", "FirstCountry");
    address secondAddress(2, "SecondAddress", 456, "SecondStreet", "22222", "SecondCountry");

    // Set nextAddress for the first address
    firstAddress.set_nextAddress(&secondAddress);

    // Test get_nextAddress
    BOOST_CHECK(firstAddress.get_nextAddress() == &secondAddress);

    // Clean up
    // Destructor is automatically called when the addresses go out of scope
}

// Sets up unit test for 'basketItem' class
#define BOOST_TEST_MODULE BasketItemTests
#include "basketItem.h"

BOOST_AUTO_TEST_CASE(test_basketItem_getters_and_setters) {
    // Create a productItem for testing
    productItem testProduct(1, "TestProduct", "TestCategory", nullptr, 10.0, 5);

    // Create a basketItem
    basketItem testBasketItem(&testProduct, 3);

    // Test getters
    BOOST_CHECK(testBasketItem.get_product() == &testProduct);
    BOOST_CHECK(testBasketItem.get_location() == nullptr);  // Assuming the location is nullptr for the test product
    BOOST_CHECK_EQUAL(testBasketItem.get_quantity(), 3);
    BOOST_CHECK(testBasketItem.get_nextItem() == nullptr);

    // Test setters
    productItem newProduct(2, "NewProduct", "NewCategory", nullptr, 20.0, 8);
    testBasketItem.set_product(&newProduct);
    BOOST_CHECK(testBasketItem.get_product() == &newProduct);

    address newLocation(1, "NewLocation", 123, "NewStreet", "54321", "NewCountry");
    testProduct.set_location(&newLocation);
    BOOST_CHECK(testBasketItem.get_location() == &newLocation);

    testBasketItem.set_quantity(5);
    BOOST_CHECK_EQUAL(testBasketItem.get_quantity(), 5);

    // Clean up
    // Destructor is automatically called when the testBasketItem and testProduct go out of scope
}

BOOST_AUTO_TEST_CASE(test_basketItem_next_item) {
    // Create two basketItems
    productItem firstProduct(1, "FirstProduct", "FirstCategory", nullptr, 10.0, 5);
    basketItem firstBasketItem(&firstProduct, 3);

    productItem secondProduct(2, "SecondProduct", "SecondCategory", nullptr, 20.0, 8);
    basketItem secondBasketItem(&secondProduct, 5);

    // Set nextItem for the first basketItem
    firstBasketItem.set_nextItem(&secondBasketItem);

    // Test get_nextItem
    BOOST_CHECK(firstBasketItem.get_nextItem() == &secondBasketItem);

    // Clean up
    // Destructor is automatically called when the basketItems go out of scope
}

// basketItem_test.cpp
#define BOOST_TEST_MODULE BasketItemTests
#include <boost/test/included/unit_test.hpp>

#include "basketItem.h"
#include "productItem.h"

BOOST_AUTO_TEST_CASE(test_basketItem_getters_and_setters) {
    // Create a productItem for testing
    productItem testProduct(1, "TestProduct", "TestCategory", nullptr, 10.0, 5);

    // Create a basketItem
    basketItem testBasketItem(&testProduct, 3);

    // Test getters
    BOOST_CHECK(testBasketItem.get_product() == &testProduct);
    BOOST_CHECK(testBasketItem.get_location() == nullptr);  // Assuming the location is nullptr for the test product
    BOOST_CHECK_EQUAL(testBasketItem.get_quantity(), 3);
    BOOST_CHECK(testBasketItem.get_nextItem() == nullptr);

    // Test setters
    productItem newProduct(2, "NewProduct", "NewCategory", nullptr, 20.0, 8);
    testBasketItem.set_product(&newProduct);
    BOOST_CHECK(testBasketItem.get_product() == &newProduct);

    address newLocation(1, "NewLocation", 123, "NewStreet", "54321", "NewCountry");
    testProduct.set_location(&newLocation);
    BOOST_CHECK(testBasketItem.get_location() == &newLocation);

    testBasketItem.set_quantity(5);
    BOOST_CHECK_EQUAL(testBasketItem.get_quantity(), 5);

    // Clean up
    // Destructor is automatically called when the testBasketItem and testProduct go out of scope
}

BOOST_AUTO_TEST_CASE(test_basketItem_next_item) {
    // Create two basketItems
    productItem firstProduct(1, "FirstProduct", "FirstCategory", nullptr, 10.0, 5);
    basketItem firstBasketItem(&firstProduct, 3);

    productItem secondProduct(2, "SecondProduct", "SecondCategory", nullptr, 20.0, 8);
    basketItem secondBasketItem(&secondProduct, 5);

    // Set nextItem for the first basketItem
    firstBasketItem.set_nextItem(&secondBasketItem);

    // Test get_nextItem
    BOOST_CHECK(firstBasketItem.get_nextItem() == &secondBasketItem);

    // Clean up
    // Destructor is automatically called when the basketItems go out of scope
}

//Set up unit test for 'package' class
#define BOOST_TEST_MODULE PackageTests

#include "package.h"

BOOST_AUTO_TEST_CASE(test_package_view_package) {
    // Create two addresses
    address fromAddress(1, "FromAddress", 123, "FromStreet", "12345", "FromCountry");
    address toAddress(2, "ToAddress", 456, "ToStreet", "67890", "ToCountry");

    // Create a productItem for testing
    productItem testProduct(1, "TestProduct", "TestCategory", nullptr, 10.0, 5);

    // Create a basketItem
    basketItem testBasketItem(&testProduct, 3);

    // Create a package
    package testPackage(&testBasketItem, &fromAddress, &toAddress);

    // Redirect cout to capture output
    stringstream capturedOutput;
    streambuf* coutBuffer = std::cout.rdbuf();
    cout.rdbuf(capturedOutput.rdbuf());

    // Test view_package
    testPackage.view_package();

    // Reset cout
    cout.rdbuf(coutBuffer);

    // Check the captured output
    string expectedOutput = "Product number:\t1\nProduct name:\tTestProduct\nProduct price:\t10\nProduct amount:\t3\nTotal cost:\t30\n\nFrom: FromAddress\nTo: ToAddress\n\n";
    BOOST_CHECK_EQUAL(capturedOutput.str(), expectedOutput);
}

BOOST_AUTO_TEST_CASE(test_package_next_package) {
    // Create two addresses
    address fromAddress(1, "FromAddress", 123, "FromStreet", "12345", "FromCountry");
    address toAddress(2, "ToAddress", 456, "ToStreet", "67890", "ToCountry");

    // Create a productItem for testing
    productItem testProduct(1, "TestProduct", "TestCategory", nullptr, 10.0, 5);

    // Create basketItems
    basketItem firstBasketItem(&testProduct, 3);
    basketItem secondBasketItem(&testProduct, 5);

    // Create packages
    package firstPackage(&firstBasketItem, &fromAddress, &toAddress);
    package secondPackage(&secondBasketItem, &fromAddress, &toAddress);

    // Test get_nextPackage
    BOOST_CHECK(firstPackage.get_nextPackage() == nullptr);

    // Set nextPackage for the first package
    firstPackage.set_nextPackage(&secondPackage);

    // Test get_nextPackage
    BOOST_CHECK(firstPackage.get_nextPackage() == &secondPackage);
    BOOST_CHECK(secondPackage.get_nextPackage() == nullptr);
}

// Set up unit test for 'shopper' class
#define BOOST_TEST_MODULE ShopperTests

BOOST_AUTO_TEST_CASE(test_shopper_options) {
    // Create a productItem for testing
    productItem testProduct(1, "TestProduct", "TestCategory", nullptr, 10.0, 5);

    // Create a shopper
    shopper testShopper(&testProduct);

    // Redirect cout to capture output
    stringstream capturedOutput;
    streambuf* coutBuffer = std::cout.rdbuf();
    cout.rdbuf(capturedOutput.rdbuf());

    // Test options
    testShopper.options();

    // Reset cout
    cout.rdbuf(coutBuffer);

    // Check the captured output
    sstring expectedOutput = "Shopper options\n1. View products\n2. View basket\n3. Update addresses\n4. View past orders\n5. Logout\nEnter option: ";
    BOOST_CHECK_EQUAL(capturedOutput.str().substr(0, expectedOutput.length()), expectedOutput);
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
