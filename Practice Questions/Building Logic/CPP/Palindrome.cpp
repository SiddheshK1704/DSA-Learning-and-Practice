#include <iostream>
using namespace std;

bool CheckPalindrome(int n){
    int original=n;
    int rev=0;
    while(n>0){
        int digit=n%10;
        rev=rev*10+digit;
        n/=10;//main logic: reversing a number
    }
    
    if(rev==original){//checking if the reversed number is equal to the original number
        return true;
    }
    return false;
}
int main()
{
    int n;
    cout<<"Enter the number:\n";
    cin>>n;
    if(CheckPalindrome(n)){
        cout<<"The number is a palindrome.\n";
    }
    else{
        cout<<"The number is not a palindrome.\n";
    }
    return 0;
}