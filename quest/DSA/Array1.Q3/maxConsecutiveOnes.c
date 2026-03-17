int findMaxConsecutiveOnes(int* nums, int numsSize) {
    // currentCount = number of consecutive 1s in the current streak
    int currentCount = 0;

    // maxCount = best result found so far
    int maxCount = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            // Extend the current streak of 1s
            currentCount++;

            // Update the maximum if needed
            if (currentCount > maxCount) {
                maxCount = currentCount;
            }
        } else {
            // A 0 breaks the streak, so reset the counter
            currentCount = 0;
        }
    }

    return maxCount;
}
