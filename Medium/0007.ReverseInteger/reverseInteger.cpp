#include <climits> // INT_MAX, INT_MIN

class Solution {
public:
    int reverse(int x) {
        int rev = 0;

        while (x != 0) {
            int digit = x % 10; // last digit (can be negative)
            x /= 10;            // remove last digit

            /*
             * We want to do: rev = rev * 10 + digit
             * but we must avoid 32-bit overflow WITHOUT using 64-bit integers.
             *
             * INT_MAX =  2147483647 -> max last digit allowed is 7
             * INT_MIN = -2147483648 -> min last digit allowed is -8
             *
             * If rev > INT_MAX/10 then rev*10 overflows.
             * If rev == INT_MAX/10 then adding digit > 7 overflows.
             *
             * Similarly for the negative side:
             * If rev < INT_MIN/10 then rev*10 overflows.
             * If rev == INT_MIN/10 then adding digit < -8 overflows.
             */
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7)) {
                return 0;
            }
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8)) {
                return 0;
            }

            rev = rev * 10 + digit;
        }

        return rev;
    }
};
