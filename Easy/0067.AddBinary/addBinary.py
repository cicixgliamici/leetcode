class Solution:
    def addBinary(self, a: str, b: str) -> str:
        # Pointers starting from the least significant bit (end of each string)
        i = len(a) - 1
        j = len(b) - 1

        carry = 0
        out = []  # we'll store result bits here (in reverse order for efficiency)

        # Continue while there are bits left in a or b, or we still have a carry
        while i >= 0 or j >= 0 or carry:
            total = carry

            # Add current bit from a (if any)
            if i >= 0:
                total += ord(a[i]) - ord('0')
                i -= 1

            # Add current bit from b (if any)
            if j >= 0:
                total += ord(b[j]) - ord('0')
                j -= 1

            # The resulting bit is total % 2, new carry is total // 2
            out.append(str(total & 1))
            carry = total >> 1

        # out is reversed (LSB first), so reverse and join into a string
        out.reverse()
        return "".join(out)