/**
 * Source: jpeg.ly/9afJz
 * Date: 2025/1/15
 * Skill:
 * Ref:
 * Runtime: 15 ms, faster than 98.39% of C++ online submissions
 * Memory Usage: 32.74 MB, less than 89.52% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      1 <= n == nums.length <= 2000
 *      1 <= nums[i] <= 50
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
const int MOD = 1e9+7, MX = 50;


class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        ll dp[2][MX+1] = {0}, res = 0;
        for (int i = 0; i <= MX; i++) {
            dp[0][i] = i <= nums[0] ? i+1 : dp[0][i-1];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= nums[i]; j++) {
                dp[1][j] = j > 0 ? dp[1][j-1] : 0;
                int y = nums[i] - j;
                int prev = nums[i-1] - y;
                if (prev < 0) continue;
                dp[1][j] = (dp[1][j] + dp[0][min(prev, j)]) % MOD;
            }
            for (int j = 0; j <= MX; j++) {
                dp[0][j] = j <= nums[i] ? dp[1][j] : dp[0][j-1];
            }
        }
        return dp[0][MX];
    }
};
