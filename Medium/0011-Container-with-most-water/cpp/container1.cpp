class Solution {
public:
    int maxArea(vector<int>& height) {
        // Start with two pointers at the extremes of the array
        int left = 0;
        int right = static_cast<int>(height.size()) - 1;

        // This variable stores the maximum area found so far
        int maxWater = 0;

        // Continue until the two pointers meet
        while (left < right) {
            // The width is the distance between the two lines
            int width = right - left;

            // The container height is limited by the shorter line
            int currentHeight = min(height[left], height[right]);

            // Compute the current area
            int currentWater = width * currentHeight;

            // Update the maximum area if needed
            maxWater = max(maxWater, currentWater);

            // Move the pointer corresponding to the shorter line
            // because only that move can potentially improve the result
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        // Return the best area found
        return maxWater;
    }
};
