#include<iostream>
#include<vector>
#include<map>
using namespace std;

int Search(vector<int> &arr, int t){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==t){
            return i;//return the index of the target if found. 
        }
    }
    return -1;
}

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
    
    int t;
    cout<<"Enter your target\n";
    cin>>t;
    
    if(Search(arr,t)==-1){
        cout<<"Element not present in array\n";
    }
    else{
        cout<<"Your element is present at index "<<Search(arr,t)<<" of the array";
    }
    
    return 0;
    
}