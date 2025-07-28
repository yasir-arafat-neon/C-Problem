#include <iostream>
#include <vector>
using namespace std;


void bubbleSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (n - i - 1); j++) {
            if (arr[j] > arr[j + 1]) {

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print a vector
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    vector<int> arr(size);  // Declare vector with given size

    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];  // Taking input for the vector
    }

    cout << "Original array: ";
    printArray(arr);  // Print original array

    bubbleSort(arr);  // Sort the array

    cout << "Sorted array: ";
    printArray(arr);  // Print sorted array

    return 0;
}
