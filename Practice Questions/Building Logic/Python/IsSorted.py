n=int(input("Enter the amount of numbers: "))
arr=[]
print("Enter the numbers")
for i in range (0,n):
    a=int(input())
    arr.append(a)

def isSorted(arr):
    for i in range(len(arr)-1):#range of the indexes
        if (arr[i]>arr[i+1]):#check the values 
            return False
    return True

if(isSorted(arr)):
    print("The array is sorted.")
else:
    print("The array is NOT sorted.")