#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        // nums.size() returns the number of elements in the vector.
        int n = nums.size();

        // Create a vector of size 2*n filled with 0.
        vector<int> ans(2 * n, 0);

        // Loop from 0 to n-1.
        for (int i = 0; i < n; i++) {
            // Copy original element into the first half.
            ans[i] = nums[i];

            // Copy the same element into the second half (shifted by +n).
            ans[i + n] = nums[i];
        }

        return ans;
    }
};
