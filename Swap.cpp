#include<iostream>
using namespace std;
int main(){
int num1,num2;
int temp;
cout<< "Please number 1 and number 2"<<endl;
cin>>num1>>num2;
temp=num1;
num1=num2;
num2=temp;

cout<< "The swapped value is:"<< "Num 1:"<< num1<< " Num2:"<< num2<<endl;

return 0;


}
