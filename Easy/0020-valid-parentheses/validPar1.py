class Solution:
    def isValid(self, s: str) -> bool:
        matching_pairs = {')': '(', '}': '{', ']': '['}                        #The dictionary is really useful to match the closing parenthesis with the opening ones
        stack = []                                                             #The keys are the closing ones, the valuse the opening
        for char in s:
            if char in matching_pairs.values():
                stack.append(char)                                             #We use the stack for the opening ones, as in the C code
            elif char in matching_pairs.keys():
                if not stack or stack[-1] != matching_pairs[char]:             #So if it's a closing one, we need to have something on the stack
                    return False                                               #and it needs to match the one on the top
                stack.pop() 
            else:                                                              #This is for non-valid characters, not useful for Leetcode
                return False
        return not stack                                                       #If the stack is empty as in the start and we got no False, then it's correct
