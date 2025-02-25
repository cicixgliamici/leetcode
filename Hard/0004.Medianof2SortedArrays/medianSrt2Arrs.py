class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # Ensure nums1 is the smaller array to simplify the binary search.
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        
        m, n = len(nums1), len(nums2)
        total_length = m + n
        half_length = (total_length + 1) // 2  # Number of elements in the left partition.

        # Perform binary search on the smaller array (nums1).
        left, right = 0, m
        while left <= right:
            # Partition nums1 at index partition1.
            partition1 = (left + right) // 2
            # Partition nums2 at index partition2 such that the left partition has half_length elements.
            partition2 = half_length - partition1

            # Handle edge cases where partitions are out of bounds.
            max_left1 = float('-inf') if partition1 == 0 else nums1[partition1 - 1]
            min_right1 = float('inf') if partition1 == m else nums1[partition1]
            max_left2 = float('-inf') if partition2 == 0 else nums2[partition2 - 1]
            min_right2 = float('inf') if partition2 == n else nums2[partition2]

            # Check if the partitioning is correct.
            if max_left1 <= min_right2 and max_left2 <= min_right1:
                # If the total number of elements is even, return the average of the two middle elements.
                if total_length % 2 == 0:
                    return (max(max_left1, max_left2) + min(min_right1, min_right2)) / 2
                # If the total number of elements is odd, return the maximum element on the left side.
                else:
                    return max(max_left1, max_left2)
            # If max_left1 > min_right2, move the partition in nums1 to the left.
            elif max_left1 > min_right2:
                right = partition1 - 1
            # If max_left2 > min_right1, move the partition in nums1 to the right.
            else:
                left = partition1 + 1
        
        # If no solution is found, return 0 (this should not happen for valid inputs).
        return 0.0


"""
Explanation of the Code:

Ensure nums1 is the Smaller Array:
- We swap nums1 and nums2 if nums1 is larger than nums2. 
  This ensures that the binary search is performed on the smaller array, reducing the number of iterations.

Binary Search Setup:
- 'left' and 'right' represent the range of indices for the binary search on nums1.
- 'partition1' is the index where nums1 is partitioned.
- 'partition2' is the corresponding index in nums2 such that the total number of elements in the left partition is 'half_length'.

Edge Cases for Partitions:
- If partition1 is 0, there are no elements on the left side of nums1, so we set max_left1 to negative infinity.
- If partition1 is m, there are no elements on the right side of nums1, so we set min_right1 to positive infinity.
- Similar logic applies to nums2.

Check Partitioning:
- If max_left1 <= min_right2 and max_left2 <= min_right1, the partitioning is correct, and we can calculate the median.
- If max_left1 > min_right2, the partition in nums1 is too far to the right, so we move right to partition1 - 1.
- If max_left2 > min_right1, the partition in nums1 is too far to the left, so we move left to partition1 + 1.

Median Calculation:
- If the total number of elements is even, the median is the average of the maximum element on the left side 
  and the minimum element on the right side.
- If the total number of elements is odd, the median is the maximum element on the left side.

Time Complexity:
- The binary search is performed on the smaller array, so the time complexity is O(log(min(m, n))).

Space Complexity:
- The algorithm uses constant extra space, so the space complexity is O(1).
"""
