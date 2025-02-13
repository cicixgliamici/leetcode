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

/*
An example in order to make it more clear (especially for myself)
Input: "abca"

Initialization:
  - String: "abca"
  - charIndex[128]: {0, 0, 0, ..., 0} (all initialized to 0)
  - maxLength = 0
  - start = 0

Steps through the string:
----------------------------------------------------------------------
Step 1:
  - end = 0, currentChar = 'a'
  - charIndex['a'] = 0 (not in the current window, since start = 0)
  - Update charIndex['a'] to end + 1 = 1
  - Calculate window length: end - start + 1 = 0 - 0 + 1 = 1
  - Update maxLength = max(0, 1) = 1

  Variables after step 1:
    start = 0, maxLength = 1, charIndex['a'] = 1

----------------------------------------------------------------------
Step 2:
  - end = 1, currentChar = 'b'
  - charIndex['b'] = 0 (not in the current window, since start = 0)
  - Update charIndex['b'] to end + 1 = 2
  - Calculate window length: end - start + 1 = 1 - 0 + 1 = 2
  - Update maxLength = max(1, 2) = 2

  Variables after step 2:
    start = 0, maxLength = 2, charIndex['b'] = 2

----------------------------------------------------------------------
Step 3:
  - end = 2, currentChar = 'c'
  - charIndex['c'] = 0 (not in the current window, since start = 0)
  - Update charIndex['c'] to end + 1 = 3
  - Calculate window length: end - start + 1 = 2 - 0 + 1 = 3
  - Update maxLength = max(2, 3) = 3

  Variables after step 3:
    start = 0, maxLength = 3, charIndex['c'] = 3

----------------------------------------------------------------------
Step 4:
  - end = 3, currentChar = 'a'
  - charIndex['a'] = 1 (in the current window, since start = 0)
  - Move start to charIndex['a'] = 1
  - Update charIndex['a'] to end + 1 = 4
  - Calculate window length: end - start + 1 = 3 - 1 + 1 = 3
  - maxLength remains max(3, 3) = 3

  Variables after step 4:
    start = 1, maxLength = 3, charIndex['a'] = 4

----------------------------------------------------------------------
Final result:
  - The length of the longest substring without repeating characters is maxLength = 3.
  - Substring: "abc"
*/
