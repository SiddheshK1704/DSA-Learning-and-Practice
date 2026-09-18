n=int(input("Enter a number: "))
original=n
digcount=0
while n>0:
    digcount+=1
    n//=10 #floor division, python has auto type conversion, this is so that the answer we get does not have decimal places
print(f"The number of digits in {original} are: {digcount}")