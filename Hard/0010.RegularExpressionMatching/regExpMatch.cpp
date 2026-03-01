#include <vector>
#include <string>
using namespace std;

/*
  LeetCode 10 - Regular Expression Matching (C++)

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

class Solution {
private:
    // Returns true if pattern char pc matches string char sc
    // '.' matches any single character
    bool charMatch(char sc, char pc) {
        return pc == '.' || sc == pc;
    }

public:
    bool isMatch(string s, string p) {
        int n = (int)s.size();
        int m = (int)p.size();

        // Use int/bool DP table: (n+1) x (m+1)
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // Empty string matches empty pattern
        dp[0][0] = true;

        // Initialize dp[0][j] for patterns like a*, a*b*, ...
        for (int j = 2; j <= m; j++) {
            if (p[j - 1] == '*') {
                // "x*" can represent empty, so skip both 'x' and '*'
                dp[0][j] = dp[0][j - 2];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] != '*') {
                    // Normal character / '.': must match current char and rely on dp[i-1][j-1]
                    if (charMatch(s[i - 1], p[j - 1])) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                } else {
                    // '*' refers to the previous pattern character p[j-2]

                    // Option 1: zero occurrences of p[j-2]
                    dp[i][j] = dp[i][j - 2];

                    // Option 2: one or more occurrences, if p[j-2] matches s[i-1]
                    if (charMatch(s[i - 1], p[j - 2])) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }

        return dp[n][m];
    }
};
