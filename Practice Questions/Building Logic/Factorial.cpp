#include <iostream> 
using namespace std; //factorial of a Number 
int fact(int n){ 
    if(n==1){
        return 1;
    }
    return n*fact(n-1);// main logic: n*factorial of its prev number, which includes fact of its prev number.
} 
int main(){ 
    int n; 
    cout<<"Enter your Number:\n"; 
    cin>>n; 
    cout<<fact(n); 
    return 0; 
}