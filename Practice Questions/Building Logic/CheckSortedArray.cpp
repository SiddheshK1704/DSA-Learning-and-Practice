#include<iostream>
#include<vector>
#include<map>
using namespace std;

bool isSorted(vector<int> &arr){
    for(int i=0;i<arr.size()-1;i++){
        if(arr[i]>arr[i+1]){//main logic: if we find even one pair that has its left number higher than the right one, that means the array is not sorted.
            return false;
        }
    }
    return true;
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
    
    if(isSorted(arr)){
        cout<<"Array is sorted.\n";
    }
    else{
        cout<<"Array is not sorted.";
    }
    return 0;
}
