from typing import List

class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        """
        LeetCode 1470 - Shuffle the Array

        nums is in the form: [x1, x2, ..., xn, y1, y2, ..., yn]
        We must return:      [x1, y1, x2, y2, ..., xn, yn]
        """

        # Create a result list of the same size as nums.
        # We'll fill it step by step.
        res = [0] * (2 * n)

        # i scans the first half (x-part): 0 .. n-1
        # j scans the second half (y-part): n .. 2n-1
        i, j = 0, n

        # k is the position where we write inside the result array.
        k = 0

        # We will produce exactly n pairs: (x1,y1), (x2,y2), ..., (xn,yn)
        while i < n:
            # Put the next element from the first half (xi)
            res[k] = nums[i]
            i += 1
            k += 1

            # Put the next element from the second half (yi)
            res[k] = nums[j]
            j += 1
            k += 1

        return res
