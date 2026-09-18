def LSearch(arr,t):
    for i in range(len(arr)):
        if(arr[i]==t):
            return i
    return -1

n=int(input("Enter the amount of numbers: "))
arr=[]
print("Enter the numbers")
for i in range (0,n):
    a=int(input())
    arr.append(a)

t=int(input("Enter the target: "))
if(LSearch(arr,t)==-1):
    print("The number is not present.")
else:
    print(f"the number is present in the array at index {LSearch(arr,t)}")
