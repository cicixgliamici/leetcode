from typing import List

class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        # len(nums) returns the number of elements in the list (its length).
        n = len(nums)

        # Create a list of size 2*n filled with zeros.
        # Syntax: [value] * k repeats "value" k times.
        ans = [0] * (2 * n)

        # range(n) generates numbers from 0 to n-1 (0-indexed loop).
        for i in range(n):
            # Copy original element into the first half.
            ans[i] = nums[i]

            # Copy the same element into the second half (shifted by +n).
            ans[i + n] = nums[i]

        return ans
