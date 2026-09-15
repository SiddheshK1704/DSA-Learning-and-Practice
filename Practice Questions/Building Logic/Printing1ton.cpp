#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number:\n";
    cin>>n;
    cout<<"Printing till n and back\n";
    for(int i=1;i<=n;i++){//main logic: understand the loop, starts from 1 and goes till n
        cout<<i<<" ";
    }
    cout<<"\n";
    for(int i=n;i>0;i--){//starts from n and goes till 1.
        cout<<i<<" ";
    }

    return 0;
}