#include <stdio.h>
#include <stdlib.h>

// Function to find two indices such that their values add up to the target
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2*sizeof(int));         //Allocate memory for the indices
    for (int i=0; i<numsSize; i++) {                   //Iterate through each element of the given array
        for (int j= i+1; j<numsSize; j++) {            //For each element, check if there is another element that adds up to the target -> O(n^2) time complexity -> must be done better
            if (nums[i] + nums[j] == target) {         //If the sum of nums[i] and nums[j] = target, store the indices
                result[0]=i;
                result[1]=j;
                *returnSize=2;                         //Set the return size to 2 (since we're returning two indices)
                return result;                         //Return the indices
            }
        }
    }
    *returnSize = 0;                                   //If no solution is found, set the return size to 0
    return NULL;
}
