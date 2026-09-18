#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    int n;
    cout<<"Enter the amount of numbers in the array:\n";
    cin>>n;
    
    cout<<"Enter the numbers in the array:\n";
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    
    int max=arr[0];
    int second=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){//main logic:
            second=max;//change second highest to the old max, since second will always be smaller than max
            max=arr[i];
        }
        else if(arr[i]>second){
            second=arr[i];//if its more than second but less than max.
        }
    }
    cout<<"The second highest number in the arrays is: "<<second<<endl;
    return 0;
}