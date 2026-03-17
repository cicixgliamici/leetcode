#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // currentCount = number of consecutive 1s in the current streak
        int currentCount = 0;
        // maxCount = best result found so far
        int maxCount = 0;
        for (int num : nums) {
            if (num == 1) {
                // Extend the current streak of 1s
                currentCount++;

                // Update the maximum if needed
                maxCount = max(maxCount, currentCount);
            } else {
                // A 0 breaks the streak, so reset the counter
                currentCount = 0;
            }
        }
        return maxCount;
    }
};
