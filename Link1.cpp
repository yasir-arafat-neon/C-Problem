#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int new_data) {
    Node* new_node = new Node(); // Allocate memory using 'new'
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}

void display() {
    Node* ptr = head;
    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main() {
    insert(3);
    insert(1);
    insert(7);
    insert(2);
    insert(9);

    cout << "The linked list is: ";
    display();

    return 0;
}
