/**
 * @file 10. Regular Expression Matching.cpp
 * @author Usama Tayyab (usamatayyab9@gmail.com)
 * @brief 
 * Problem : https://leetcode.com/problems/regular-expression-matching/description/
 * Problem statement:
 * Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
 *  '.' Matches any single character.​​​​
 *  '*' Matches zero or more of the preceding element.
 * The matching should cover the entire input string (not partial).
 * Example 1:
 *  Input: s = "aa", p = "a"
 *  Output: false
 *  Explanation: "a" does not match the entire string "aa".
 * Example 2:
 *  Input: s = "aa", p = "a*"
 *  Output: true
 *  Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
 * Example 3:
 *  Input: s = "ab", p = ".*"
 *  Output: true
 *  Explanation: ".*" means "zero or more (*) of any character (.)".
 * Constraints:
 *  1 <= s.length <= 20
 *  1 <= p.length <= 20
 *  s contains only lowercase English letters.
 *  p contains only lowercase English letters, '.', and '*'.
 *  It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();

    // Create a DP table to store matching results.
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    // Empty string and empty pattern always match.
    dp[0][0] = true;

    // Handle patterns like "a*b*c*".
    for (int j = 1; j <= n; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }

    // Fill in the DP table.
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
            }
        }
    }

    return dp[m][n];
}
};