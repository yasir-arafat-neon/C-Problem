#include <iostream>
using namespace std;

int main() {
    int mimo[10] = {32, 4, 5, 12, 5, 54, 6, 23, 3, 5}; // Declaration of the array
    int n, i;
    cout << "Enter the number to be searched:" << endl;
    cin >> n; // Inputting the number to be searched in the array

    bool found = false; // To track if the number is found
    for (i = 0; i < 10; i++) { // Searching begins
        if (n == mimo[i]) {
            found = true; // Number is found
            break; // Exit the loop
        }
    }

    if (found) {
        cout << n << " was found in index " << i << " of the array." << endl;
    } else {
        cout << n << " was not found in the array." << endl;
    }

    return 0;
}
