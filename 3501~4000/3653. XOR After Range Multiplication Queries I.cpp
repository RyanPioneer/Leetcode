/*
 * @lc app=leetcode id=3653 lang=cpp
 *
 * [3653] XOR After Range Multiplication Queries I
 */

// @lc code=start
#define ll long long
const int mod = 1e9 + 7;
class Solution {
   public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for (auto& q : queries) {
            for (int i = q[0]; i <= q[1]; i += q[2]) {
                nums[i] = (ll)nums[i] * q[3] % mod;
            }
        }
        int result = 0;
        for (auto& i : nums) {
            result ^= i;
        }
        return result;
    }
};
// @lc code=end
