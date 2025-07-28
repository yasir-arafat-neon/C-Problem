#include<iostream>
using namespace std;
int main(){
int index;
int mimo[10] = {32,4,5,12,5,54,6,23,3,5}; // declaration of a new array
int n;
cout<<"Enter the number to be searched:"<<endl;
cin>>n; // inputting the number to be searched in the array
for(int i=0; i<10; i++)
 // searching begins
if (n == mimo[i]){
	 index = i;
	  break;

	  // searching ends


cout<<n<< " "<<" was found in index "<< index << " of the array. "<<endl;}
else {
    cout<< "No data was found"<<endl;
}
return 0;
}
