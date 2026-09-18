#include <iostream>
using namespace std;

bool CheckPrime(int n){
    if(n<=1){
        return false;
    }
    for(int i=2;i*i<=n;i++){//checking uptill the square root makes it more efficient, as u have to got through a lot less.
        if(n%i==0){//dividing the number by all possible numbers. 
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cout<<"Enter the number:\n";
    cin>>n;
    if(CheckPrime(n)){
        cout<<"The number is prime.\n";
    }
    else{
        cout<<"The number is NOT prime.\n";
    }
    return 0;
}