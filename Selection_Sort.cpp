#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int>&arr)
{   int n= arr.size();
    for (int i=0;i<n;i++)
    {
        int min=i;
    for (int j=i+1;j<n;j++)
    {
        if (arr[j]<arr[min])
        {
            min=j;
        }
      }
    if (min!=i)
    {
        swap(arr[i],arr[min]);
    }
    }
}

void printArray(const vector<int>&arr)
{
    for (int num:arr)
    {
        cout<< num << " ";
    }
    cout<< endl;
}
int main()
{
   int size;
   cout<< "enter size of array:"<<endl;
   cin>> size;
   vector<int>arr(size);
   cout<< "Enter "<< size << "elements:";
   for (int i=0;i<size;i++)
   {
       cin>>arr[i];
   }
   cout<< "Original array:";
   printArray(arr);

   selectionSort(arr);

   cout<< "Sorted array:";
   printArray(arr);

   return 0;
}
