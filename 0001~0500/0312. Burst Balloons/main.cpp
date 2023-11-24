/**
 * Source: is.gd/axfmDY
 * Date: 2023/11/24
 * Skill:
 * Ref:
 * Runtime: 174 ms, faster than 95.87% of C++ online submissions
 * Memory Usage: 8.70 MB, less than 90.39% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
const int MX = 302;


class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = SZ(nums), dp[MX][MX] = {0};
        if (n == 1) return nums[0];
        dp[1][1] = nums[0] * nums[1];
        dp[n][n] = nums[n - 2] * nums[n - 1];
        for (int i = 1; i < n - 1; i++) {
            dp[i + 1][i + 1] = nums[i - 1] * nums[i] * nums[i + 1];
        }
        for (int len = 2; len <= n; len++) {
            for (int start = 1; start + len <= n + 1; start++) {
                int end = start + len - 1;
                for (int last = start; last <= end; last++) {
                    int first = start == 1 ? 1 : nums[start - 2];
                    int third = end == n ? 1 : nums[end];
                    dp[start][end] = max(dp[start][end], dp[start][last - 1] + dp[last + 1][end] + first * nums[last - 1] * third);
                }
            }
        }
        return dp[1][n];
    }
};