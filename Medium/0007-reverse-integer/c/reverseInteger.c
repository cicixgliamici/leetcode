#include <limits.h>

int reverse(int x) {
    int rev = 0;

    while (x != 0) {
        int digit = x % 10;   // take last digit (can be negative if x is negative)
        x /= 10;              // remove last digit

        /*
         * Before doing: rev = rev * 10 + digit
         * we must ensure it will not overflow 32-bit signed int.
         *
         * INT_MAX =  2147483647  -> last digit limit is 7
         * INT_MIN = -2147483648  -> last digit limit is -8
         *
         * If rev > INT_MAX/10, then rev*10 already overflows.
         * If rev == INT_MAX/10, then adding a digit > 7 overflows.
         *
         * Similarly for negative side with INT_MIN.
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
