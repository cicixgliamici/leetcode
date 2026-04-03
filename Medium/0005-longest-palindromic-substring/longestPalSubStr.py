class Solution:
    def longestPalindrome(self, s: str) -> str:
        # Handle edge case where the string is empty
        if len(s) < 1:
            return ""
        
        # Initialize variables to track the start and end indices of the longest palindrome found
        start = 0
        end = 0
        
        # Helper function to expand around the center defined by left and right indices
        def expand(l: int, r: int) -> tuple[int, int]:
            # Expand outwards while the characters at l and r are equal and within the string bounds
            while l >= 0 and r < len(s) and s[l] == s[r]:
                l -= 1
                r += 1
            # Return the adjusted indices (the loop exits when the characters don't match, so we backtrack once)
            return (l + 1, r - 1)
        
        # Iterate through each character in the string as a potential center
        for i in range(len(s)):
            # Check for odd-length palindromes (center is a single character)
            l_odd, r_odd = expand(i, i)
            # Check for even-length palindromes (center is between two characters)
            l_even, r_even = expand(i, i + 1)
            
            # Determine the maximum length palindrome found from the two checks
            # Calculate the length by (r - l) because (end - start) gives the correct comparison
            if r_odd - l_odd > end - start:
                start, end = l_odd, r_odd
            if r_even - l_even > end - start:
                start, end = l_even, r_even
        
        # Extract and return the longest palindrome substring
        return s[start:end + 1]