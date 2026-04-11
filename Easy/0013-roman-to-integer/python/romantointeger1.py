#The solution inside the while is similar to the one in romantoinger1.c, but here we use a "data structure" (a dictionary)
#in which we codify the roman values to the respetciv number in our decimal base, so that when we read
#we already know the value we are referring to
class Solution:
    def romanToInt(self, s: str) -> int:
        roman_values = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
        total = 0
        i = 0
        while i < len(s):
            if i+1 < len(s) and roman_values[s[i]] < roman_values[s[i+1]]:
                total += roman_values[s[i+1]] - roman_values[s[i]]
                i+ 2
            else:
                total += roman_values[s[i]]
                i+=1
        return total
