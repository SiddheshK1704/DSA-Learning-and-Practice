#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number:\n";
    cin>>n;
    int rev=0;//main logic: Initiate the reverse number with 0. 
    cout<<"Reverse of the given number is:\n";
    while(n>0){
        int digit=n%10;//extract the digit by mod operation
        rev=rev*10+digit;//reverse*10 creates space, and then the remainder is added. 
        n/=10;
    }
    cout<<rev<<endl;
    return 0;
}