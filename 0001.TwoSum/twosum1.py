class Solution:
    def twoSum(self, nums, target):
        for i in range(len(nums)):                                          # Iterate through each element in the array
            for j in range(i + 1, len(nums)):                               # For each element, check if there's another element that adds up to the target
                if nums[i] + nums[j] == target:                             # If the sum equals the target, return the indices 
                    return [i, j]
