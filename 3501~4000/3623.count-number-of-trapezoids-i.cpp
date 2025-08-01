/*
 * @lc app=leetcode id=3623 lang=cpp
 *
 * [3623] Count Number of Trapezoids I
 */

// @lc code=start
#define ll long long
const int MOD = 1e9 + 7;
class Solution {
   public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<ll, ll> mp;
        for (auto& p : points) {
            mp[p[1]]++;
        }
        ll res = 0, total = 0;
        vector<int> nums;
        for (auto i : mp) {
            ll num = i.second * (i.second - 1) / 2 % MOD;
            nums.push_back(num);
            total += num;
        }
        for (auto i : nums) {
            res = (res + i * (total - i) % MOD) % MOD;
            total -= i;
        }
        return res;
    }
};
// @lc code=end
