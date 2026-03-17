class Solution:
    def myAtoi(self, s: str) -> int:
        # 32-bit signed integer limits
        INT_MIN = -2**31
        INT_MAX = 2**31 - 1

        n = len(s)
        i = 0

        # 1) Skip leading whitespaces
        while i < n and s[i] == ' ':
            i += 1

        # 2) Check sign
        sign = 1
        if i < n and (s[i] == '+' or s[i] == '-'):
            if s[i] == '-':
                sign = -1
            i += 1

        # 3) Skip leading zeros
        while i < n and s[i] == '0':
            i += 1

        # 4) Read digits and build the number
        result = 0
        while i < n and s[i].isdigit():
            digit = ord(s[i]) - ord('0')

            # Before adding the new digit, check if it would overflow
            # Example:
            # result = 214748364 and digit = 8
            # for positive => overflow if result > INT_MAX // 10
            # or result == INT_MAX // 10 and digit > 7
            if result > INT_MAX // 10 or (result == INT_MAX // 10 and digit > 7):
                if sign == 1:
                    return INT_MAX
                else:
                    return INT_MIN

            result = result * 10 + digit
            i += 1

        # 5) Apply sign
        result *= sign

        return result
