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

// Node structure for the linked list
struct Node {
    Product data;
    Node* next;
};

// Function to calculate price difference using an array
float priceDifferenceArray(Product products[], int size) {
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

// Function to calculate total stock value using an array
float totalStockValueArray(Product products[], int size) {
    float totalValue = 0;
    for (int i = 0; i < size; i++) {
        totalValue += products[i].price * products[i].stockQuantity;
    }
    return totalValue;
}

// Function to find affordable products using an array
void findAffordableProductsArray(Product products[], int size) {
    cout << "Affordable products (price <= 50) using array:" << endl;
    for (int i = 0; i < size; i++) {
        if (products[i].price <= 50) {
            cout << products[i].productName << " - $" << products[i].price << endl;
        }
    }
}

// Function to insert a new product into the linked list
void insert(Node*& head, Product product) {
    Node* newNode = new Node{product, nullptr};
    newNode->next = head;
    head = newNode;
}

// Function to calculate price difference using a linked list
float priceDifferenceList(Node* head) {
    float maxPrice = INT_MIN;
    float minPrice = INT_MAX;

    Node* current = head;
    while (current != nullptr) {
        if (current->data.price > maxPrice) {
            maxPrice = current->data.price;
        }
        if (current->data.price < minPrice) {
            minPrice = current->data.price;
        }
        current = current->next;
    }
    return maxPrice - minPrice;
}

// Function to calculate total stock value using a linked list
float totalStockValueList(Node* head) {
    float totalValue = 0;
    Node* current = head;

    while (current != nullptr) {
        totalValue += current->data.price * current->data.stockQuantity;
        current = current->next;
    }
    return totalValue;
}

// Function to find affordable products using a linked list
void findAffordableProductsList(Node* head) {
    cout << "Affordable products (price <= 50) using linked list:" << endl;
    Node* current = head;
    while (current != nullptr) {
        if (current->data.price <= 50) {
            cout << current->data.productName << " - $" << current->data.price << endl;
        }
        current = current->next;
    }
}

int main() {
    // Array of products
    Product products[] = {
        {1, "Laptop", 999.99, 10, "Electronics"},
        {2, "Smartphone", 499.99, 15, "Electronics"},
        {3, "Book", 20.00, 50, "Education"},
        {4, "Pen", 2.50, 100, "Stationery"},
        {5, "Mouse", 25.00, 30, "Accessories"}
    };
    int size = 5;

    // Linked list of products
    Node* head = nullptr;
    for (int i = 0; i < size; i++) {
        insert(head, products[i]);
    }

    // Array-based operations
    cout << "Using Array:" << endl;
    cout << "Price difference: $" << priceDifferenceArray(products, size) << endl;
    cout << "Total stock value: $" << totalStockValueArray(products, size) << endl;
    findAffordableProductsArray(products, size);

    cout << endl;

    // Linked list-based operations
    cout << "Using Linked List:" << endl;
    cout << "Price difference: $" << priceDifferenceList(head) << endl;
    cout << "Total stock value: $" << totalStockValueList(head) << endl;
    findAffordableProductsList(head);

    return 0;
}

