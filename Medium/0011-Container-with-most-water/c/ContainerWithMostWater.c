int maxArea(int* height, int heightSize) {
    // Start with two pointers at the extremes of the array
    int left = 0;
    int right = heightSize - 1;

    // This variable stores the maximum area found so far
    int maxWater = 0;

    // Continue until the two pointers meet
    while (left < right) {
        // The width is the distance between the two lines
        int width = right - left;

        // The container height is limited by the shorter line
        int currentHeight = (height[left] < height[right]) ? height[left] : height[right];

        // Compute the current area
        int currentWater = width * currentHeight;

        // Update the maximum area if needed
        if (currentWater > maxWater) {
            maxWater = currentWater;
        }

        // Move the pointer corresponding to the shorter line
        // because moving the taller one cannot improve the area
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    // Return the best area found
    return maxWater;
}
