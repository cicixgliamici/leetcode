/*
 * This function returns the index where 'target' is found in the sorted array 'nums'.
 * If the target is not found, it returns the index where the target should be inserted 
 * to keep the array sorted.
 */

int searchInsert(int* nums, int numsSize, int target) {
    // Define the start and end pointers for binary search
    int left = 0;
    int right = numsSize - 1;
    
    // Perform binary search
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Calculate the midpoint
        if (nums[mid] == target) {
            // If the target is found at mid, return mid
            return mid;
        } else if (nums[mid] < target) {
            // If the element at mid is less than target, move the left pointer
            left = mid + 1;
        } else {
            // If the element at mid is greater than target, move the right pointer
            right = mid - 1;
        }
    }
    
    // If we exit the loop, it means the target was not found.
    // At this point, 'left' is the correct insertion position.
    return left;
}

/*
 * Explanation of the algorithm:
 * 
 * We use a binary search approach. We maintain two pointers 'left' and 'right', 
 * which initially refer to the start and end of the array, respectively. 
 * We repeatedly calculate the midpoint and compare the target with the element at the midpoint:
 *
 * 1) If they are equal, we return the midpoint index.
 * 2) If the target is greater than the element at mid, we shift our search to the subarray on the right.
 * 3) If the target is less than the element at mid, we shift our search to the subarray on the left.
 *
 * If the target is not found by the time our pointers cross, the 'left' pointer indicates 
 * the correct insertion position for the target in the sorted array.
 *
 * Time Complexity:
 * The time complexity of the binary search algorithm is O(log n), 
 * because we continually divide the search space in half with each comparison.
 */
