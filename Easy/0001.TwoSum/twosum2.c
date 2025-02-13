#include <stdio.h>
#include <stdlib.h>

//Structure to store an index and the value pairs of an array's element
typedef struct {
    int value;
    int index;
} Pair;

//Compares the value field of two elements ​​in the array
int compare(const void* a, const void* b) {
    Pair* pairA = (Pair*)a;                           //The compare function must cast the two values ​​because in C, the qsort function requires the compare function 
    Pair* pairB = (Pair*)b;                           //to take two const void* pointers as arguments, regardless of the data type the array contains.
    return pairA->value - pairB->value;               //This is a requirement of the signature of the compare function used by qsort
}

//Function to find two indices that sum to the target
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Pair* pairs = (Pair*)malloc(numsSize * sizeof(Pair));              //As in twosum1.c we need to allocate memory for the solution
    for (int i = 0; i < numsSize; i++) {                               //Just one lap -> O(n)
        pairs[i].value = nums[i];
        pairs[i].index = i;
    }
    qsort(pairs, numsSize, sizeof(Pair), compare);                    //Qsort is for construction O(n*log n) in the worst case
    int left=0;
    int right=numsSize-1;
    while (left < right) {                                            //Just one lap -> O(n)
        int sum = pairs[left].value+pairs[right].value;
        if (sum==target) {
            int* result = (int*)malloc(2*sizeof(int));
            result[0] = pairs[left].index;
            result[1] = pairs[right].index;
            *returnSize=2;
            free(pairs);
            return result;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    *returnSize = 0;
    free(pairs);
    return NULL;                                                   //The complexity is O(n)+O(n*log n)=O(n*log n), way better of the O(n^2) we had in the first run
}
