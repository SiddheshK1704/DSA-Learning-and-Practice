n=int(input("Enter a number: "))
def isPalindrome(n):
    original=n
    rev=0
    while n>0:
        digit=n%10
        rev=rev*10+digit
        n//=10
    if(rev==original):
        return True
    return False
if(isPalindrome(n)):
    print("The Number is a Palindrome number.")
else:
    print("The Number is not a Palindrome number.")