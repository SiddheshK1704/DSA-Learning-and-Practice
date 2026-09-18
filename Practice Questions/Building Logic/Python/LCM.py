a=int(input("Enter 1st number: "))
b=int(input("Enter 2nd number: "))
def gcd(a,b):
    while b!=0:
        temp=b
        b=a%b #to find the remainder
        a=temp#swap
        
    return a
    
lcm=int((a*b)/gcd(a,b))

print(f"The LCM of the two numbers is:{lcm}")
        