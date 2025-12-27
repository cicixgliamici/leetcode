class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes.
        // If it ends with 0, it can only be palindrome if it is exactly 0.
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int reversedHalf = 0;

        // Build the reversed second half of the number.
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + (x % 10);
            x /= 10;
        }

        // If the length is even, x should equal reversedHalf.
        // If the length is odd, ignore the middle digit in reversedHalf.
        return (x == reversedHalf) || (x == reversedHalf / 10);
    }
};
