#include <string>
#include <algorithm>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        int i = (int)a.size() - 1;  // index from the end of a
        int j = (int)b.size() - 1;  // index from the end of b
        int carry = 0;

        std::string res;
        res.reserve(std::max(a.size(), b.size()) + 1); // avoid repeated reallocations

        // Add bits from right to left (LSB to MSB)
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            // Convert current char bit to int (0/1) and add it
            if (i >= 0) sum += (a[i--] - '0');
            if (j >= 0) sum += (b[j--] - '0');

            // Current result bit is sum % 2, next carry is sum / 2
            res.push_back(char('0' + (sum & 1)));
            carry = (sum >> 1);
        }

        // We built the result reversed, so reverse it to correct order
        std::reverse(res.begin(), res.end());
        return res;
    }
};