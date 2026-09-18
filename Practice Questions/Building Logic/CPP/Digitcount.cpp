#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number:\n";
    cin>>n;
    int digitcount=0;
    while(n>0){
        n=n/10;//main logic: keep dividing the number by 10, so that you get each digit
        digitcount++;
    }
    cout<<"Digit count of the number is:\n";
    cout<<digitcount<<endl;

    return 0;
}