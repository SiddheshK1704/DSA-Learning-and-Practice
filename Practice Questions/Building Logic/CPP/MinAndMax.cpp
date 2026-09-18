#include<iostream>
#include<vector>
#include<map>
using namespace std;

int MinMax(vector<int> &arr){//min and max function
    int min=arr[0];
    int max=arr[0];
    for(int i=0;i<arr.size();i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            min=arr[i];
        }
    }
    cout<<"The Maximum number in the array is: "<<max<<" and the minimum number in the array is: "<<min<<endl;
    
    return 0;
}
int main(){
    
    cout<<"Enter the amount of numbers:\n";
    int n;
    cin>>n;
    cout<<"Enter the numbers:\n";
    
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);//input the numbers in the array.
    }
    
    MinMax(arr);
    return 0;
}