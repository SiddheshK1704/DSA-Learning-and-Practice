n=int(input("Enter the number:"))
def fib(n):
    if(n==0):
        return 0
    elif(n==1):
        return 1
    return fib(n-1)+fib(n-2)

seq=[]
for i in range(0,n+1):
    seq.append(fib(i))
print(f"Fibonacci number of {n} is: {fib(n)}")
print(f"The Fibonacci sequence till n numbers is:")
for i in seq:
    print(i)