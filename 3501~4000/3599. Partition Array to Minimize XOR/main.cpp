/**
 * Source: t.ly/9dr1_
 * Date: 2025/7/27
 * Skill:
 * Ref:
 * Runtime: 265 ms, faster than 90.15% of C++ online submissions
 * Memory Usage: 32.44 MB, less than 94.70% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *		1 <= nums.length <= 250
 */

#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7, MX = 251;

class Solution {
   public:
    int minXor(vector<int>& nums, int k) {
        int dp[MX][MX];
        memset(dp, 0x3f, sizeof(dp));
        for (int i = 0, num = 0; i < nums.size(); ++i) {
            num ^= nums[i];
            dp[i][1] = num;
        }
        for (int i = 2; i <= k; i++) {
            for (int j = i - 1; j < nums.size(); j++) {
                int num = nums[j];
                dp[j][i] = max(dp[j - 1][i - 1], num);
                for (int l = j - 1; l > 0; l--) {
                    num ^= nums[l];
                    int mx = max(dp[l - 1][i - 1], num);
                    dp[j][i] = min(dp[j][i], mx);
                }
            }
        }
        return dp[nums.size() - 1][k];
    }
};
