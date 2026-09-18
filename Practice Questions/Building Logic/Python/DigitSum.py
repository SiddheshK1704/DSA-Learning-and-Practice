n=int(input("Enter a number: "))
original=n
digsum=0
while n>0:
    digit=n%10
    digsum+=digit
    n//=10
print(f"The sum of digits of {original} is: {digsum}")