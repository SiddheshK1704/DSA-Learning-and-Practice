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
    
    int left=0;//left and right are indices(pointers to swap)
    int right=arr.size()-1;
    
    while(left<right){//main swapping logic. If a and b are to be swapped, temp=a, a=b(the main swap) and then b=temp(making the swap complete)
        int temp=arr[left];
        arr[left]=arr[right];
        arr[right]=temp;
        left++;//incrementing left and right
        right--;
    }
    
    cout<<"The reversed array is:\n";
    for(auto i:arr){
        cout<<i<<" ";
    }
    
    return 0;
    
}