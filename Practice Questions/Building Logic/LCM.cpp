#include <iostream>
#include <vector>
using namespace std;
int gcd(int a, int b){//gcd function. 
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
int lcm(int a, int b){//lcm function.
    return (a*b)/gcd(a,b); //Very important: LCM(a,b) = (a*b)/GCD(a,b) since we know the product of numbers is equal to the product of their GCD and LCM.
}
int main(){
    int a, b;
    cout<<"Enter the two numbers:\n";
    cin>>a>>b;
        
    cout<<"The GCD and LCM of the two numbers are:\n";
    cout<<"GCD: "<<gcd(a,b)<<"\n";
    cout<<"LCM: "<<lcm(a,b)<<endl;
    
    return 0;
}