/** 
 * Source: https://leetcode.com/problems/regular-expression-matching/
 * Date: 2021/7/15
 * Skill: DP
 * Constraints: 
 *      0 <= s.length <= 20
 *      0 <= p.length <= 30
 *      s contains only lowercase English letters.
 *      p contains only lowercase English letters, '.', and '*'.
 *      It is guaranteed for each appearance of the character '*', 
 *      there will be a previous valid character to match.
 * 
 * 1. dp[i][j] = dp[i - 1][j - 1], if p[j - 1] != '*' && 
 * (s[i - 1] == p[j - 1] || p[j - 1] == '.');
 * 2. dp[i][j] = dp[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 time;
 * 3. dp[i][j] = dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), 
 * 4. if p[j - 1] == '*' and the pattern repeats for at least 1 time.
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];
    }
};

//more concise:

/*class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<bool> cur(n + 1, false);
        for (int i = 0; i <= m; i++) {
            bool pre = cur[0];
            cur[0] = !i;
            for (int j = 1; j <= n; j++) {
                bool temp = cur[j];
                if (p[j - 1] == '*') {
                    cur[j] = cur[j - 2] || (i && cur[j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    cur[j] = i && pre && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
                pre = temp;
            }
        }
        return cur[n];
    }
};*/