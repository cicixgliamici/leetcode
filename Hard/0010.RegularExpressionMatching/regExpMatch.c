#include <stdbool.h>
#include <string.h>

/*
  LeetCode 10 - Regular Expression Matching

  dp[i][j] means:
    - s[0..i-1] matches p[0..j-1] (i chars of s, j chars of p)

  Transitions:
    1) If p[j-1] != '*':
         dp[i][j] = dp[i-1][j-1] AND charMatch(s[i-1], p[j-1])
    2) If p[j-1] == '*':
         Two options:
           a) Use '*' as "zero occurrence" of p[j-2]:
                dp[i][j] = dp[i][j-2]
           b) Use '*' as "one or more occurrences" (only if p[j-2] matches s[i-1]):
                dp[i][j] |= dp[i-1][j]
*/

static bool charMatch(char sc, char pc) {
    // '.' matches any single character
    return (pc == '.') || (sc == pc);
}

bool isMatch(char* s, char* p) {
    int n = (int)strlen(s);
    int m = (int)strlen(p);

    // Constraints are small (<= 20), so a simple O(n*m) DP is perfect.
    bool dp[21][21];
    memset(dp, 0, sizeof(dp));

    // Empty string matches empty pattern
    dp[0][0] = true;

    // Initialize dp[0][j]: empty string vs pattern like a*, a*b*, ...
    for (int j = 2; j <= m; j++) {
        if (p[j - 1] == '*') {
            // '*' can eliminate the previous element, so we skip 2 pattern chars
            dp[0][j] = dp[0][j - 2];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] != '*') {
                // Must match current characters and rely on dp[i-1][j-1]
                if (charMatch(s[i - 1], p[j - 1])) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            } else {
                // p[j-1] == '*', it refers to p[j-2]
                // Option 1: treat "x*" as empty (zero occurrences)
                dp[i][j] = dp[i][j - 2];

                // Option 2: if p[j-2] matches s[i-1], consume one char from s
                // and keep pattern at j (because '*' can match multiple chars)
                if (charMatch(s[i - 1], p[j - 2])) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
            }
        }
    }

    return dp[n][m];
}
