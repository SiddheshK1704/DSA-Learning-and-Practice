a=int(input("Enter 1st number: "))
b=int(input("Enter 2nd number: "))
def gcd(a,b):
    while b!=0:
        temp=b
        b=a%b #to find the remainder
        a=temp#swap
        
        '''dry run:
        a = 12, b = 18
        
        b != 0
        temp = 18
        b = 12 % 18 = 12
        a = 18
        
        b != 0
        temp = 12
        b = 18 % 12 = 6
        a = 12
        
        b != 0
        temp = 6
        b = 12 % 6 = 0
        a = 6
        
        GCD = 6'''
        
    return a
    
print(f"The GCD of the two numbers is: {gcd(a,b)}")
        