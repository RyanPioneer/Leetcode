/*
 * @lc app=leetcode id=3596 lang=cpp
 *
 * [3596] Minimum Cost Path with Alternating Directions I
 */

// @lc code=start
class Solution {
   public:
    int minCost(int m, int n) {
        if (m == 1 && n == 1) return 1;
        if ((m == 2 && n == 1) || (m == 1 && n == 2)) return 3;
        return -1;
    }
};
// @lc code=end
