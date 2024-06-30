/**
 * Source: ibit.ly/7D9CO
 * Date: 2024/6/30
 * Skill:
 * Ref:
 * Runtime: 105 ms, faster than 25.00% of C++ online submissions
 * Memory Usage: 128.77 MB, less than 12.50% of C++ online submissions
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
    int maximumLength(vector<int>& nums, int k) {
        int res = 0;
        vector<vector<int>> dp(k, vector<int>(k, 0));
        for (auto &i: nums) {
            i %= k;
            for (int j = 0; j < k; j++) {
                int prev = (j + k - i) % k;
                dp[j][i] = dp[j][prev] + 1;
                res = max(res, dp[j][i]);
            }
        }
        return res;
    }
};