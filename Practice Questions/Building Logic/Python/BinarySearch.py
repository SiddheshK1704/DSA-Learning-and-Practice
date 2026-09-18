def BinarySearch(arr,t):#very important condition: The array ,ust be sorted before binary search.
    low=arr[0]
    high=arr[len(arr)-1]
    while(low<=high):
        mid=low+(high-low)//2#remove the auto type conversion error by using // instead of /
        if(arr[mid]==t):
            return mid
        elif(arr[mid]<t):
            low=mid+1
        else:
            high=mid-1
    return -1
n=int(input("Enter the amount of numbers: "))
arr=[]
print("Enter the numbers")
for i in range (0,n):
    a=int(input())
    arr.append(a)

t=int(input("Enter the target: "))
if(BinarySearch(arr,t)==-1):
    print("The number is not present.")
else:
    print(f"the number is present in the array at index {BinarySearch(arr,t)}")
