class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        """
        strStr finds the index of the first occurrence of the string 'needle' 
        in the string 'haystack'. If 'needle' is not found, returns -1.

        This function implements a straightforward approach by checking every 
        possible starting position in 'haystack'. Whenever the substring of 
        length 'len(needle)' matches 'needle', the index is returned.
        """
        # If needle is empty, by convention, we can return 0.
        if len(needle) == 0:
            return 0

        # If needle's length is greater than haystack's length,
        # needle cannot possibly be in haystack.
        if len(needle) > len(haystack):
            return -1

        # Loop through haystack until there's not enough room for needle to fit.
        for i in range(len(haystack) - len(needle) + 1):
            # Compare the substring of haystack with needle.
            if haystack[i:i+len(needle)] == needle:
                return i  # First matching index.

        # If no match was found, return -1.
        return -1
