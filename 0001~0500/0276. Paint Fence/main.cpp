/**
 * Source: t.ly/MDQH3
 * Date: 2025/4/11
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 7.96 MB, less than 68.70% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      1 <= n <= 50
 *      1 <= k <= 10 ** 5
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

const int MX = 50;

class Solution {
   public:
    int numWays(int n, int k) {
        if (n > 2 && k == 1) return 0;
        int dp[MX] = {k, k * k};
        for (int i = 2; i < n; ++i) {
            dp[i] = (dp[i - 1] + dp[i - 2]) * (k - 1);
        }
        return dp[n - 1];
    }
};
