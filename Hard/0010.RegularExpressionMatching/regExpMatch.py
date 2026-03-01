class Solution:
    """
    LeetCode 10 - Regular Expression Matching (Python)

    dp[i][j] means:
      s[0:i] matches p[0:j]  (i chars of s, j chars of p)

    Transitions:
      1) If p[j-1] != '*':
           dp[i][j] = dp[i-1][j-1] and charMatch(s[i-1], p[j-1])
      2) If p[j-1] == '*':
           '*' refers to p[j-2]. Two options:
             a) zero occurrences: dp[i][j] = dp[i][j-2]
             b) one or more occurrences (if p[j-2] matches s[i-1]):
                    dp[i][j] |= dp[i-1][j]
    """

    def isMatch(self, s: str, p: str) -> bool:
        n, m = len(s), len(p)

        def char_match(sc: str, pc: str) -> bool:
            # '.' matches any single character
            return pc == '.' or sc == pc

        # DP table (n+1) x (m+1)
        dp = [[False] * (m + 1) for _ in range(n + 1)]
        dp[0][0] = True  # empty string matches empty pattern

        # Initialize dp[0][j] for patterns like a*, a*b*, ...
        for j in range(2, m + 1):
            if p[j - 1] == '*':
                dp[0][j] = dp[0][j - 2]  # "x*" can be skipped entirely

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if p[j - 1] != '*':
                    # Need a direct character match and dp[i-1][j-1] to be true
                    if char_match(s[i - 1], p[j - 1]):
                        dp[i][j] = dp[i - 1][j - 1]
                else:
                    # '*' refers to p[j-2]
                    # Option 1: treat "x*" as empty (zero occurrences)
                    dp[i][j] = dp[i][j - 2]

                    # Option 2: use one or more occurrences if p[j-2] matches s[i-1]
                    if char_match(s[i - 1], p[j - 2]):
                        dp[i][j] = dp[i][j] or dp[i - 1][j]

        return dp[n][m]
