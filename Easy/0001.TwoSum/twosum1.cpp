#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Try all pairs (i, j) with i < j, exactly like the Java brute force approach.
        for (int i = 0; i < (int)nums.size(); i++) {
            for (int j = i + 1; j < (int)nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        // If not found, return an empty vector (same as new int[0] in Java).
        return {};
    }
};
