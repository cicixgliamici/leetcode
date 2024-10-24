#The explanation is equal to the one written in palindrome 1.c, the only difference is that there is 
#no limitation on int length in Python, so we do not check it out
class Solution:
    def isPalindrome(self, x: int) -> bool: 
        if x < 0:
            return False                     # Negative numbers are not palindromes
        original = x
        reversed_num = 0
        while x > 0:
            last_digit = x % 10 
            reversed_num = reversed_num * 10 + last_digit
            x //= 10 
        return original == reversed_num
