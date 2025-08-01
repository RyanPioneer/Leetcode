/*
 * @lc app=leetcode id=3583 lang=cpp
 *
 * [3583] Count Special Triplets
 */

// @lc code=start
#define ll long long
const int MOD = 1e9 + 7, MX = 1e5 + 1;
class Solution {
   public:
    int specialTriplets(vector<int> &nums) {
        ll res = 0;
        int n = nums.size(), post[MX] = {0}, pre[MX] = {0};
        for (auto &n : nums) {
            post[n]++;
        }
        for (auto &n : nums) {
            post[n]--;
            if (n * 2 < MX) res = (res + (ll)pre[n * 2] * post[n * 2]) % MOD;
            pre[n]++;
        }
        return res;
    }
};
// @lc code=end
