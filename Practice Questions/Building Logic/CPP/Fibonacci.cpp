//Fibonacci sequence is a mathematical series in which each number is the sum of the two preceding ones, usually starting with 0 and 1.
// The sequence goes: 0, 1, 1, 2, 3, 5, 8, 13, 21, and so on.
// F(n) = F(n-1) + F(n-2), where F(0) = 0 and F(1) = 1

#include <iostream> 
using namespace std; //fibonacci sequence 
int Fib(int n){ 
    if(n==0){ 
        return 0; 
    }
    if(n==1){ 
        return 1; 
    }
    return Fib(n-1)+Fib(n-2); 
} 
int main(){ 
    int n; 
    cout<<"Enter your Number:\n"; 
    cin>>n; 
    cout<<Fib(n); 
    return 0; 
}

//code for fibonacci sequence using recursion.