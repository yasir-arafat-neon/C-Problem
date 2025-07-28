#include <iostream>
using namespace std;

void swapp(int *a, int *b, int &exchanges)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    exchanges++;
}

void selectionSort(int arr[], int n, int &comparisons, int &exchanges)
{
    for (int i = 0; i < n - 1; i++)
        {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
            {
            comparisons++;
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            swapp(&arr[i], &arr[minIndex], exchanges);
        }
    }
}

void printArray(int arr[], int n) {

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n, comparisons = 0, exchanges = 0;

    cout << "ENTER THE SIZE OF ARRAY: " << endl;
    cin >> n;

    int arr[n];
    cout << "ENTER ELEMENTS OF THE ARRAY: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    selectionSort(arr, n, comparisons, exchanges);
    printArray(arr, n);

    cout << "NUMBER OF COMPARISONS: " << comparisons << endl;
    cout << "NUMBER OF EXCHANGES: " << exchanges << endl;

    return 0;
}
