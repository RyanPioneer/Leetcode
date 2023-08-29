/**
 * Source: https://rb.gy/5d13i
 * Date: 2023/8/29
 * Skill:
 * Runtime: 65 ms, faster than 99.88% of C++ online submissions
 * Memory Usage: 83.95 MB, less than 38.83% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= m <= 300
 *      m <= n <= 10 ** 5
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

#define ll long long
// using ll = long long;


class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size(), res = INT_MIN;
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, INT_MIN / 2));
        dp[0][0] = 0;
        for (int i = 1; i <= m; i++) {
            dp[0][i] = dp[0][i - 1] + nums[n - i] * multipliers[i - 1];
            dp[i][0] = dp[i - 1][0] + nums[i - 1] * multipliers[i - 1];
            for (int j = 1; j < i; j++)
                dp[j][i - j] = max(dp[j - 1][i - j] + nums[j - 1] * multipliers[i - 1],
                                   dp[j][i - j - 1] + nums[n - (i - j)] * multipliers[i - 1]);
        }
        for (int i = 0; i <= m; i++)
            res = max(res, dp[i][m - i]);
        return res;
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    vector<int> tasks{1,2,3,1};
}