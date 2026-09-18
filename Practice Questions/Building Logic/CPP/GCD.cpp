#include <iostream>
#include <vector>
using namespace std;
int gcd(int a, int b){
    while(b!=0){
        int temp = b;
        b=a%b;
        a=temp;//swap 
    }
    return a;
}
/* dry run:
a = 12, b = 18

b != 0
temp = 18
b = 12 % 18 = 12
a = 18

b != 0
temp = 12
b = 18 % 12 = 6
a = 12

b != 0
temp = 6
b = 12 % 6 = 0
a = 6

GCD = 6
*/

int main()
{
    int a, b;
    cout<<"Enter the two numbers:\n";
    cin>>a>>b;
    
    cout<<"the GCD of the two numbers is:\n";
    cout<<gcd(a,b);
    return 0;
}
