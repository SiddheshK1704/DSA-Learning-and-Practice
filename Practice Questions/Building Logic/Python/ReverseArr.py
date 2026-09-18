n=int(input("Enter the amount of numbers: "))
arr=[]
print("Enter the numbers")
for i in range (0,n):
    a=int(input())
    arr.append(a)

left=0
right=len(arr)-1
while (left<=right):
    temp=arr[right]#main swapping logic
    arr[right]=arr[left]
    arr[left]=temp
    right-=1
    left+=1
print("The reversed array is: ")
for i in arr:
    print(i)