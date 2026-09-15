#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number:\n";
    cin>>n;
    
    vector<int> ans;
    for(int i=1;i<=n;i++){//main logic: check for all numbers that divide n and then put them into an array.
        if(n%i==0){
            ans.push_back(i);
        }
    }
    cout<<"The list of divisors are as follows:\n";
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}