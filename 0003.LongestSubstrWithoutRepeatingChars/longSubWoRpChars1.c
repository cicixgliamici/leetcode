/* Sliding Window Explanation:
 * The sliding window technique is used to efficiently find a solution to problems
 * involving subarrays or substrings. It maintains two pointers (`start` and `end`)
 * that represent the current window of interest.
 * 
 * In this problem:
 * The `start` pointer marks the beginning of the substring being checked.
 * The `end` pointer iterates through the string to expand the window.
 * If a character is repeated in the window, `start` is moved forward to exclude it.
 * During each step, the length of the current window (`end-start+1`) is calculated,
 * and the maximum length of a substring without repeating characters is updated.
 */

#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);                                      //Get the length of the input string
    if (n == 0) return 0;                                   //If the string is empty, return 0
    int charIndex[128] = {0};                               //Array to store the last position of each ASCII character
    int maxLength = 0;                                      //Variable to store the maximum length of substring
    int start = 0;                                          //Start of the sliding window
    for (int end = 0; end < n; end++) {                     //Iterate through the string
        char currentChar = s[end];                          //Get the current character
        if (charIndex[currentChar] > start) {               //If the character is already in the current window, move the start
            start = charIndex[currentChar];                 //of the window to the right of its last occurrence
        }
        charIndex[currentChar] = end+1;                     //Update the last seen position of the current character
        int windowLength = end - start+1;                   //Calculate the length of the current window
        if (windowLength > maxLength) {                     //Update maxLength if the current window is longer
            maxLength = windowLength;
        }
    }
    return maxLength;                                       //Return the maximum length of substring without repeating characters
}

/* Time Complexity: O(n)
 * Each character in the string is processed at most twice: once when expanding
 * the `end` pointer and once when adjusting the `start` pointer.
 * Therefore, the overall time complexity is linear with respect to the length of the string.
 * 
 * Space Complexity: O(1)
 * The algorithm uses a fixed-size array (`charIndex[128]`) to store the last seen positions of characters.
 * Since the array size is constant (128 for ASCII characters), the space complexity is O(1).
 */ 
