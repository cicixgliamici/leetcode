#include <stdlib.h>

/**
 * Note:
 * - The returned array must be malloced.
 * - The caller is responsible for freeing it.
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    // numsSize is the number of elements in the input array.
    int n = numsSize;

    // The result array has size 2*n.
    *returnSize = 2 * n;

    // Allocate memory for the result array.
    int* ans = (int*)malloc((*returnSize) * sizeof(int));

    // Fill the first half and the second half with the same values.
    for (int i = 0; i < n; i++) {
        // Copy original element into the first half.
        ans[i] = nums[i];

        // Copy the same element into the second half (shifted by +n).
        ans[i + n] = nums[i];
    }

    return ans;
}
