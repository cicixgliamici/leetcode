class Solution:
    def plusOne(self, digits):  # Aggiungi 'self' come primo parametro
        # Start from the last digit
        i = len(digits) - 1
        
        # Iterate through the digits from the end to the beginning
        while i >= 0:
            # If the current digit is less than 9, simply increment it and return the result
            if digits[i] < 9:
                digits[i] += 1
                return digits
            else:
                # If the current digit is 9, set it to 0 and move to the previous digit
                digits[i] = 0
                i -= 1
        
        # If all digits were 9, we need to add a new digit '1' at the beginning
        return [1] + digits