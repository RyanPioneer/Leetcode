/*
 * @lc app=leetcode id=3577 lang=cpp
 *
 * [3577] Count the Number of Computer Unlocking Permutations
 */

// @lc code=start
const int MOD = 1e9 + 7;
#define ll long long
class Solution {
   public:
    int countPermutations(vector<int>& complexity) {
        for (int i = 1; i < complexity.size(); i++) {
            if (complexity[i] <= complexity[0]) {
                return 0;
            }
        }
        ll ans = 1;
        for (int i = 1; i < complexity.size(); i++) {
            ans = (ans * i) % MOD;
        }
        return ans;
    }
};
// @lc code=end
