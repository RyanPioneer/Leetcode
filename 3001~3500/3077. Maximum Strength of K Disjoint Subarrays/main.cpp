/**
 * Source: is.gd/gjasiO
 * Date: 2024/4/16
 * Skill:
 * Ref:
 * Runtime: 1752 ms, faster than 50.76% of C++ online submissions
 * Memory Usage: 589.72 MB, less than 9.19% of C++ online submissions
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
    long long maximumStrength(vector<int>& nums, int k) {
        nums.insert(begin(nums), 0);

        int n = nums.size();
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(k + 1, vector<ll>(2, LLONG_MIN/2)));

        for (int i = 0; i < n; i++) {
            dp[i][0][0] = 0;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= min(i, k); j++) {
                int sign = j % 2 ? 1 : -1;

                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1]);
                dp[i][j][1] = max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) + (ll)nums[i] * sign * (k - j + 1);
                dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][1] + (ll)nums[i] * sign * (k - j + 1));
            }
        }
        return max(dp[n - 1][k][0], dp[n - 1][k][1]);
    }
};