freq={} #initialize a dictionary(key value pairs) instead of a map(in cpp)
n=int(input("Enter the amount of numbers: "))
arr=[]
print("Enter the numbers in the array")
for i in range (1,n+1):
    a=int(input())#input the numbers in the array
    arr.append(a)
    
for i in arr:
    if i in freq: #if its present, increment
        freq[i]+=1
    else:
        freq[i]=1#if not, change frequency to 1.
        
print(freq)