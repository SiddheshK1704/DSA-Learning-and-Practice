n=int(input("Enter a number: "))
def isPrime(n):
    if n == 1:
        return False
    for i in range (2, int(n**0.5)+1):#till n^0.5, because it is only necessary to check till there
        if(n%i==0):
            return False
    
    return True

if(isPrime(n)):
    print(f"The number {n} is Prime")
else:
    print("The number is not Prime")
        