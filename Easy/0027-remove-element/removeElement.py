class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k = 0  # Pointer to the last unique element
        for i in range(len(nums)):
            if nums[i] != val:
                nums[k] = nums[i]  # Place the non-val element at index k
                k += 1
        return k  # Return the new length of the list
