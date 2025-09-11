/*
 * @lc app=leetcode id=3675 lang=cpp
 *
 * [3675] Minimum Operations to Transform String
 */

// @lc code=start
#define ll long long
class Solution {
   public:
    int minOperations(string s) {
        int res = 0;

        for (char c : s) {
            res = max(res, ('z' - c + 1) % 26);
        }

        return res;
    }
};
// @lc code=end
