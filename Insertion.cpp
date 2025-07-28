#include<iostream>
using namespace std;
int main(){
int k, i, n=5, mimo[10]={2, 3, 5, 6, 7}; //partial initialization; n=total elements
mimo[n++] = 8;         // insert value 8 at the end of the array; increase n;
/* insert value 1 at the beginning of array */
for(i=n; i>0; i--)      //shift all the values one index forward. i.e. the value
   mimo[i] = mimo[i-1]; //in index 1 goes to 2, 2 goes to 3,…, (n-1)th goes to nth.
mimo[0] = 1; n++;       //1 is inserted at index 1; n increases;
// insert value 4 in the middle (index k=3) of the array
k = 3;
for(i=n; i>k; i--)      //shift all the values one index forward. i.e. the value
   mimo[i] = mimo[i-1]; //in index k goes to k+1,…, (n-1)th goes to nth.
mimo[k] = 4; n++;       //4 is inserted at index k; n increases;
for(i=0; i<n; i++)      //printing all the values in the array after insert
   cout << mimo[i];
   return 0;
}

