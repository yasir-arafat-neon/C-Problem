#include <iostream>
using namespace std;

void binarySearch() {
    const int n = 10;
    int arr[n] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};

    cout << "Enter your number for Binary Search: ";
    int key;
    cin >> key;

    int first = 0, last = n - 1;
    bool found = false;

    while (first <= last) {
        int mid = first + (last - first) / 2;

        if (arr[mid] == key) {
            cout << key << " is found at index: " << mid << endl;
            found = true;
            break;
        } else if (key > arr[mid]) {
            first = mid + 1;
        } else {
            last = mid - 1;
        }
    }

    if (!found) {
        cout << key << " is not found." << endl;
    }
}
