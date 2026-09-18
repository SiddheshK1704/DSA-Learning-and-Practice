n=int(input("Enter n: "))
def fact(n):
    if n==0 or n==1:
        return 1
    return n*fact(n-1)
print(f"The factorial of {fact(n)}")