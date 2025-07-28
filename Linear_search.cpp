#include<iostream>
#include<vector>
using namespace std;
void linearSearch(vector<int>array,int m)
{
    int n=array.size();

    int found=0;
    int i;
    for (i=0;i<n;i++)
    {
        if(array[i]==m)
        {

            found++;
            break;
        }

    }
    if(found==1)
        {
            cout<< "data found:"<< i<<endl;
        }
        else{
            cout <<"Data was not found";
        }
}
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}
int main()
{   int m,n;
    cout<< "Enter array size:"<<endl;
    cin>>n;

    vector<int> array(n);
    cout<< "Enter value to search:"<<endl;
    cin>> m;
    cout<< "Enter array:";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    cout << "Original array: ";
    printArray(array);
    cout<< "Searched:";
    linearSearch(array,m );

}

