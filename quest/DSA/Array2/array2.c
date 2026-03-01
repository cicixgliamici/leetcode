#include <stdlib.h>

/*
 * LeetCode 1470 - Shuffle the Array
 *
 * nums is in the form: [x1, x2, ..., xn, y1, y2, ..., yn]
 * We must return:      [x1, y1, x2, y2, ..., xn, yn]
 *
 * Example:
 * nums = [2,5,1,3,4,7], n = 3
 * first half  = [2,5,1]
 * second half = [3,4,7]
 * result      = [2,3,5,4,1,7]
 */

/**
 * Note about LeetCode C signature:
 * - We must allocate the result array with malloc.
 * - We must set *returnSize to the length of the returned array.
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
    // The output will always have the same size as the input: 2n.
    *returnSize = numsSize;

    // Allocate memory for the result array.
    // In LeetCode, the caller will free this memory.
    int *res = (int*)malloc(numsSize * sizeof(int));
    if (res == NULL) {
        // If allocation fails, returnSize should be 0 (safe behavior).
        *returnSize = 0;
        return NULL;
    }

    /*
     * We will use:
     * i -> index for x-part (0 ... n-1)
     * j -> index for y-part (n ... 2n-1)
     * k -> index for result (0 ... 2n-1)
     */
    int i = 0;      // starts from x1
    int j = n;      // starts from y1
    int k = 0;      // position in the result array

    // While we still have elements in the first half (there are exactly n pairs)
    while (i < n) {
        // Place xi
        res[k++] = nums[i++];

        // Place yi
        res[k++] = nums[j++];
    }

    return res;
}
