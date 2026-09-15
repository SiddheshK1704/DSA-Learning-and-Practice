#include <iostream>
using namespace std;


int main()
{
    int n;
    cout<<"Enter the number:\n";
    cin>>n;
    int sumofdigs=0;
    while(n>0){
        int digit=n%10;//main logic: extract the last digit and add it to the sum. 
        sumofdigs+=digit;
        n/=10;
    }
    cout<<"Sum of digits is:\n";
    cout<<sumofdigs<<endl;
    return 0;
}