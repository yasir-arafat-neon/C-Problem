#include <iostream>
using namespace std;

void swapp(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion(int arr[], int n, int &comparisons, int &shifts)
{
    for (int i = 1; i < n; i++)
        {
        for (int j = i - 1; j < n - 1; j++)
        {
            comparisons++;
            if (arr[i - 1] > arr[j + 1])
            {
                swapp(&arr[i - 1], &arr[j + 1]);
                shifts++;
            }
        }
    }
}

void print(int arr[], int n) {

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int comparisons = 0, shifts = 0;

    insertion(arr, n, comparisons, shifts);
    print(arr, n);

    cout << "Number of comparisons: " << comparisons << endl;
    cout << "Number of shifts: " << shifts << endl;

    return 0;
}
