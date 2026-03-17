class Solution {
public:
    int myAtoi(string s) {
        // 32-bit signed integer limits
        int INT_MIN_VAL = -2147483648;
        int INT_MAX_VAL = 2147483647;

        int i = 0;
        int n = s.length();

        // 1) Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2) Check sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        // 3) Skip leading zeros
        while (i < n && s[i] == '0') {
            i++;
        }

        // 4) Read digits and build the number
        // We use long long to safely detect overflow before returning
        long long result = 0;

        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check overflow before actually updating result
            // If result is already too large, or adding this digit
            // would make it exceed 32-bit signed integer range,
            // clamp immediately.
            if (result > INT_MAX_VAL / 10 ||
                (result == INT_MAX_VAL / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX_VAL : INT_MIN_VAL;
            }

            result = result * 10 + digit;
            i++;
        }

        // 5) Apply sign
        result *= sign;

        return (int)result;
    }
};
