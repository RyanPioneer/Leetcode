/**
 * Source: t.ly/IlgQ1
 * Date: 2025/4/10
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 13.08 MB, less than 91.67% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
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

class Solution {
   public:
    int minCost(vector<vector<int>>& costs) {
        int dp[2][3] = {0};
        for (int i = 0; i < 3; i++) {
            dp[0][i] = costs[0][i];
        }
        for (int i = 1; i < costs.size(); i++) {
            for (int j = 0; j < 3; j++) {
                dp[i % 2][j] = costs[i][j] + min(dp[(i - 1) % 2][(j + 1) % 3],
                                                 dp[(i - 1) % 2][(j + 2) % 3]);
            }
        }
        return min(
            dp[(costs.size() - 1) % 2][0],
            min(dp[(costs.size() - 1) % 2][1], dp[(costs.size() - 1) % 2][2]));
    }
};