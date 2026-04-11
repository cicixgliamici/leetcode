class Solution:
    def maxArea(self, height):
        # Start with two pointers at the extremes of the array
        left = 0
        right = len(height) - 1

        # This variable stores the best area found so far
        max_water = 0

        # Continue until the two pointers meet
        while left < right:
            # The width of the container is the distance between the two lines
            width = right - left

            # The height of the container is limited by the shorter line
            current_height = min(height[left], height[right])

            # Compute the area formed by the two lines
            current_water = width * current_height

            # Update the maximum area if the current one is better
            if current_water > max_water:
                max_water = current_water

            # Move the pointer pointing to the shorter line
            # because only this can potentially lead to a taller boundary
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1

        # Return the maximum amount of water found
        return max_water
