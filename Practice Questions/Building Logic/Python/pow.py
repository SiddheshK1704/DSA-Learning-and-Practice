n=int(input("Enter the number:"))
m=int(input("Enter the power:"))
ans=1
for i in range (1, m+1):
    ans*=n
    
print(f"The number raised to the power {m} gives us: {ans}")