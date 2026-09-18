#include<iostream>
#include<vector>
#include<map>
using namespace std;

int BinarySearch(vector<int> &arr, int t){
    int low=0;
    int high = arr.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;//middle element
        
        if(arr[mid]==t){//if the target is in the middle
            return mid;
        }
        else if(arr[mid]<t){//if arr[mid]<t; then we change low to mid +1, then the whole thing is calculated again.
            low=mid+1;
        }
        else{//or high is changed to mid-1
            high=mid-1;
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
    
    if(BinarySearch(arr,t)==-1){
        cout<<"Element not present in array\n";
    }
    else{
        cout<<"Your element is present at index "<<BinarySearch(arr,t)<<" of the array";
    }
    
    return 0;
    
}