#include <climits>

class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes.
        if (x < 0) return false;

        int original = x;
        int reversed = 0;

        while (x > 0) {
            int lastDigit = x % 10;

            // Overflow check for reversed * 10 + lastDigit
            if (reversed > (INT_MAX - lastDigit) / 10) {
                return false;
            }

            reversed = reversed * 10 + lastDigit;
            x /= 10;
        }

        return original == reversed;
    }
};
