/**
 * Source: ibit.ly/lALpO
 * Date: 2024/6/24
 * Skill:
 * Ref:
 * Runtime: 83 ms, faster than 57.14% of C++ online submissions
 * Memory Usage: 76.07 MB, less than 71.43% of C++ online submissions
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
#define ll long long


class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        ll dp[2][2];
        dp[0][0] = nums[0], dp[0][1] = LLONG_MIN / 2;
        for (int i = 1; i < n; i++) {
            dp[1][0] = nums[i] + max(dp[0][0], dp[0][1]);
            dp[1][1] = dp[0][0] - nums[i];
            dp[0][0] = dp[1][0];
            dp[0][1] = dp[1][1];
        }
        return max(dp[0][0], dp[0][1]);
    }
};