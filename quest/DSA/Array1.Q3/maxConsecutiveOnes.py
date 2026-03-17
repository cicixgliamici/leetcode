from typing import List

class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        # current_count = number of consecutive 1s in the current streak
        current_count = 0
        
        # max_count = best result found so far
        max_count = 0

        for num in nums:
            if num == 1:
                # Extend the current streak of 1s
                current_count += 1
                
                # Update the maximum if needed
                max_count = max(max_count, current_count)
            else:
                # A 0 breaks the streak, so reset the counter
                current_count = 0

        return max_count
