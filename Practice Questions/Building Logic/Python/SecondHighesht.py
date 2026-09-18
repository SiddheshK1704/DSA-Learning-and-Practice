arr=[]
n=int(input("Enter the amount of numbers: "))
print("Enter the numbers")
for i in range (0,n):
    a=int(input())
    arr.append(a)
    
highest=arr[0]
second=arr[0]
for i in arr:
    if(i>highest):
        second=highest
        highest=i
    elif(i>second):
        second=i
        
print(f"The Second Highest Number in this array is: {second}")