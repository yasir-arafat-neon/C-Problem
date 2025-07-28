#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr, int& comparisons, int& shifts) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        //comparisons++; // Counting the initial comparison for the while loop
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            shifts++; // Counting each shift operation
            j--;
            comparisons++; // Counting each comparison in the while loop
        }
        arr[j + 1] = temp;
        // If no shifting was done, decrement the shift count to avoid overcounting
        if (j == i - 1) {
            //shifts--;
        }
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    vector<int> arr(size);
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << "Original array: ";
    printArray(arr);

    int comparisons = 0, shifts = 0;
    insertionSort(arr, comparisons, shifts);

    cout << "Sorted array: ";
    printArray(arr);
    cout << "Number of comparisons: " << comparisons << endl;
    cout << "Number of shifts: " << shifts << endl;

    return 0;
}
