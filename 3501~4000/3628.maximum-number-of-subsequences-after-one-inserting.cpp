/*
 * @lc app=leetcode id=3628 lang=cpp
 *
 * [3628] Maximum Number of Subsequences After One Inserting
 */

// @lc code=start

#define ll long long

class Solution {
   public:
    long long numOfSubsequences(string s) {
        int n = s.length();

        // used for checking the maximum number of subsequences if we insert 'C'
        vector<ll> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1] + (s[i] == 'T');
        }

        ll res = 0, lNum = 0, cNum = 0, lcNum = 0, ctNum = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            auto c = s[i];
            if (c == 'L') {
                lNum++;
            } else if (c == 'C') {
                lcNum += lNum;
                cNum++;
            } else if (c == 'T') {
                ctNum += cNum;
                res += lcNum;
            }
            mx = max(mx, lNum * dp[i + 1]);
        }

        mx = max({mx, lcNum, ctNum});
        return res + mx;
    }
};
// @lc code=end
