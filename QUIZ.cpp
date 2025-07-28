#include <iostream>
#include <string>
#include <climits>
using namespace std;

// Node structure for the linked list
struct Node {
    int productId;
    string productName;
    float price;
    int stockQuantity;
    string category;
    Node* next;
};

// Function to insert a new product into the linked list
void insert(Node*& head, int id, string name, float price, int stockQuantity, string category) {
    Node* newNode = new Node{id, name, price, stockQuantity, category, nullptr};
    newNode->next = head;
    head = newNode;
}

// Function to calculate the price difference between the most expensive and the cheapest product
float priceDifference(Node* head) {
    float maxPrice = INT_MIN;
    float minPrice = INT_MAX;

    Node* current = head;
    while (current != nullptr) {
        if (current->price > maxPrice) {
            maxPrice = current->price;
        }
        if (current->price < minPrice) {
            minPrice = current->price;
        }
        current = current->next;
    }
    return maxPrice - minPrice;
}

// Function to calculate total stock value for all products
float totalStockValue(Node* head) {
    float totalValue = 0;
    Node* current = head;
    while (current != nullptr) {
        totalValue += current->price * current->stockQuantity;
        current = current->next;
    }
    return totalValue;
}

// Function to find and print products with a price <= 50
void findAffordableProducts(Node* head) {
    Node* current = head;
    cout << "Affordable products (price <= 50):" << endl;
    while (current != nullptr) {
        if (current->price <= 50) {
            cout << current->productName << " - $" << current->price << endl;
        }
        current = current->next;
    }
}

int main() {
    Node* head = nullptr;

    // Insert products into the linked list
    insert(head, 1, "Laptop", 999.99, 10, "Electronics");
    insert(head, 2, "Smartphone", 499.99, 15, "Electronics");
    insert(head, 3, "Book", 20.00, 50, "Education");
    insert(head, 4, "Pen", 2.50, 100, "Stationery");
    insert(head, 5, "Mouse", 25.00, 30, "Accessories");

    cout << "Price difference: $" << priceDifference(head) << endl;
    cout << "Total stock value: $" << totalStockValue(head) << endl;
    findAffordableProducts(head);

    return 0;
}
