/*
 * @lc app=leetcode id=3557 lang=cpp
 *
 * [3557] Find Maximum Number of Non Intersecting Substrings
 */

// @lc code=start
class Solution {
   public:
    int maxSubstrings(string word) {
        int res = 0, n = word.size();
        vector<int> dp(n + 1, 0);
        deque<int> q[26];
        for (int i = 0; i < n; i++) {
            dp[i + 1] = dp[i];
            int id = word[i] - 'a';
            int num = dp[i];
            if (q[id].empty()) {
                q[id].push_back(i);
            } else {
                int last = -1;
                while (!q[id].empty() && i - q[id].front() >= 3) {
                    last = q[id].front();
                    q[id].pop_front();
                    dp[i + 1] = max(dp[i + 1], dp[last] + 1);
                }
                if (last != -1) {
                    q[id].push_front(last);
                }
                q[id].push_back(i);
            }
        }
        return dp[n];
    }
};
// @lc code=end
