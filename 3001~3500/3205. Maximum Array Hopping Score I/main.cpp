/**
 * Source: ibit.ly/DyekC
 * Date: 2024/8/16
 * Skill:
 * Ref:
 * Runtime: 149 ms, faster than 30.77% of C++ online submissions
 * Memory Usage: 31.14 MB, less than 22.65% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>
#include <functional>
#include <list>


using namespace std;


class Solution {
public:
    int maxScore(vector<int>& nums) {
        int res = 0, n = nums.size();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            for (int prev = i - 1; prev >= 0; prev--) {
                if (dp[i] < dp[prev] + (i - prev) * nums[i]) {
                    dp[i] = dp[prev] + (i - prev) * nums[i];
                }
            }
        }
        return dp[n-1];
    }
};