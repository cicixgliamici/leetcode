#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // seen[value] = index of the first occurrence seen so far
        unordered_map<int, int> seen;

        for (int i = 0; i < (int)nums.size(); i++) {
            int x = nums[i];
            int complement = target - x;

            auto it = seen.find(complement);
            if (it != seen.end()) {
                // Found complement earlier at it->second
                return {it->second, i};
            }

            // Store current value with its index
            seen[x] = i;
        }

        // If not found, return empty (same behavior as your Java code)
        return {};
    }
};
