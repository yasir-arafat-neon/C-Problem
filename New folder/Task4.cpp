#include <iostream>
using namespace std;

void linearSearch()
{
    int sear[7] = {10, 20, 30, 40, 50, 60, 70};
    int i;
    int n;

    cout << "Enter your number for Linear Search: ";
    cin >> n;

    for (i = 0; i < 7; i++)
        {
        if (n == sear[i])
        {
            break;
        }
    }

    cout << n << " is found on index " << i << " of the array named 'sear'." << endl;
}

void binarySearch()
{
    int n = 10;
    int arr[n] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};

    cout << "Enter your number for Binary Search: ";
    int key;
    cin >> key;
    int mid;
    int first = 0, last = n - 1;
    bool found = false;

    for (; first <= last;)
        {
        mid = (first + last)/2;

        if (arr[mid] == key)
        {
            cout << key << " is found in index: " << mid << endl;
            found = true;
            break;
        }
        else if (key > arr[mid])
        {
            first = mid + 1;
        }
        else if (key < arr[mid])
        {
            last = (mid - 1);
        }
    }

    if (found == false)
    {
        cout << key << " is not found." << endl;
    }
}

int main()
{
    cout << "Choose search method:\n";
    cout << "1. Linear Search\n";
    cout << "2. Binary Search\n";
    cout << "Enter your choice (1 or 2): ";
    int choice;
    cin >> choice;

    if (choice == 1)
    {
        linearSearch();
    }
    else if (choice == 2)
    {
        binarySearch();
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
