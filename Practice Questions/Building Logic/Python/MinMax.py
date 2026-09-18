arr=[]
n=int(input("Enter the amount of numbers: "))
print("Enter the numbers")
for i in range (0,n):
    a=int(input())
    arr.append(a)
    
max=arr[0]
min=arr[0]
for i in arr:
    if(i>max):
        max=i
    if(i<min):
        min=i
        
print(f"The max in this array is {max} and the min in this array is {min}")