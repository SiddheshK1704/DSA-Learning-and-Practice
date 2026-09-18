#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number:\n";
    cin>>n;
    cout<<"sum of n numbers is:\n";
    int sum=0;
    for(int i=1; i<=n;i++){
        sum+=i;//main logic:iteratively adding each number to the sum.
    }
    cout<<sum<<endl;
    return 0;
}