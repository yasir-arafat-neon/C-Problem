#include <iostream>
using namespace std;

void swapp(int *a, int *b, int &shifts)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
    shifts += 1;
}

void bubbleSort(int arr[], int n, int &comparisons, int &shifts)
{
    for (int i = 0; i < n - 1; i++)
        {
        for (int j = 0; j < n - i - 1; j++)
        {
            comparisons++;
            if (arr[j] > arr[j + 1])
            {
                swapp(&arr[j], &arr[j + 1], shifts);
            }
        }
    }
}

void printArray(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    int comparisons = 0;
    int shifts = 0;
    cout << "ENTER THE SIZE OF ARRAY: " << endl;
    cin >> n;
    int arr[n];

    cout << "ENTER ELEMENTS OF THE ARRAY: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr, n, comparisons, shifts);
    printArray(arr, n);

    cout << "NUMBER OF COMPARISONS: " << comparisons << endl;
    cout << "NUMBER OF SHIFTS: " << shifts << endl;

    return 0;
}

