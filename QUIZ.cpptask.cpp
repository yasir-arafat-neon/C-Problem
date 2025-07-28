#include <iostream>
#include <string>
#include <climits> // For INT_MAX and INT_MIN
using namespace std;

// Structure to store product details
struct Product {
    int productId;
    string productName;
    float price;
    int stockQuantity;
    string category;
};

// Function to calculate the price difference between the most expensive and the cheapest product
float priceDifference(Product products[], int size) {
    float maxPrice = INT_MIN;
    float minPrice = INT_MAX;

    for (int i = 0; i < size; i++) {
        if (products[i].price > maxPrice) {
            maxPrice = products[i].price;
        }
        if (products[i].price < minPrice) {
            minPrice = products[i].price;
        }
    }
    return maxPrice - minPrice;
}

// Function to calculate total stock value for all products
float totalStockValue(Product products[], int size) {
    float totalValue = 0;
    for (int i = 0; i < size; i++) {
        totalValue += products[i].price * products[i].stockQuantity;
    }
    return totalValue;
}

// Function to find and print products with a price <= 50
void findAffordableProducts(Product products[], int size) {
    cout << "Affordable products (price <= 50):" << endl;
    for (int i = 0; i < size; i++) {
        if (products[i].price <= 50) {
            cout << products[i].productName << " - $" << products[i].price << endl;
        }
    }
}

int main() {
    Product products[] = {
        {1, "Laptop", 999.99, 10, "Electronics"},
        {2, "Smartphone", 499.99, 15, "Electronics"},
        {3, "Book", 20.00, 50, "Education"},
        {4, "Pen", 2.50, 100, "Stationery"},
        {5, "Mouse", 25.00, 30, "Accessories"}
    };
    int size = 5;

    cout << "Price difference: $" << priceDifference(products, size) << endl;
    cout << "Total stock value: $" << totalStockValue(products, size) << endl;
    findAffordableProducts(products, size);

    return 0;
}

