#include <stdlib.h>
#include <string.h>

/*
 * LeetCode 67 - Add Binary
 *
 * Given two binary strings a and b, return their sum as a binary string.
 *
 * Idea:
 * - We add bits starting from the end (least significant bit), exactly like manual addition.
 * - Keep a "carry" (0 or 1).
 * - The result length is at most max(len(a), len(b)) + 1 (when there's a final carry).
 *
 * Complexity:
 * - Time:  O(n), where n = max(len(a), len(b))
 * - Space: O(n) for the output string
 */
char* addBinary(char* a, char* b) {
    int la = (int)strlen(a);
    int lb = (int)strlen(b);

    // Maximum possible length is max(la, lb) + 1 (extra carry),
    // plus 1 for the null terminator.
    int maxLen = (la > lb ? la : lb);
    char *out = (char*)malloc((maxLen + 2) * sizeof(char));
    if (!out) return NULL;

    int i = la - 1;   // pointer for string a (from the end)
    int j = lb - 1;   // pointer for string b (from the end)
    int carry = 0;    // carry can be 0 or 1
    int k = 0;        // current size of the result (we build it reversed)

    // Build the result from least significant bit to most significant bit
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        // Convert current char bit to integer (0/1) and add it
        if (i >= 0) sum += (a[i--] - '0');
        if (j >= 0) sum += (b[j--] - '0');

        // The resulting bit is sum % 2, the next carry is sum / 2
        out[k++] = (char)('0' + (sum & 1));
        carry = (sum >> 1);
    }

    // Now out[0..k-1] contains the result reversed.
    // Reverse it in-place to get the correct binary string.
    for (int left = 0, right = k - 1; left < right; left++, right--) {
        char tmp = out[left];
        out[left] = out[right];
        out[right] = tmp;
    }

    out[k] = '\0'; // null-terminate the string
    return out;
}