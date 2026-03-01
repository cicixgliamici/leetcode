class Solution:
    def reverse(self, x: int) -> int:
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31

        # Work with absolute value to avoid Python's tricky % and // behavior on negatives
        n = abs(x)
        rev = 0

        while n != 0:
            digit = n % 10      # last digit in [0..9]
            n //= 10            # remove last digit

            # rev = rev * 10 + digit could overflow 32-bit after we re-apply the sign.
            # Since rev is non-negative here, we only need to check against INT_MAX.
            if rev > INT_MAX // 10 or (rev == INT_MAX // 10 and digit > 7):
                return 0

            rev = rev * 10 + digit

        # Re-apply the sign
        rev = rev if x >= 0 else -rev

        # Final guard (useful for clarity; overflow is already prevented above)
        if rev < INT_MIN or rev > INT_MAX:
            return 0

        return rev
