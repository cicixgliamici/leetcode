class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        # Strip trailing spaces to handle cases where there are spaces at the end
        s = s.rstrip()
        
        # Split the string into words based on spaces
        words = s.split(' ')
        
        # The last word is the last element in the list
        last_word = words[-1]
        
        # Return the length of the last word
        return len(last_word)