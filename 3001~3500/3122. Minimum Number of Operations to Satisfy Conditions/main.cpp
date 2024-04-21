/**
 * Source: is.gd/GtsQ2B
 * Date: 2024/4/21
 * Skill:
 * Ref:
 * Runtime: 220 ms, faster than 55.56% of C++ online submissions
 * Memory Usage: 114.47 MB, less than 11.11% of C++ online submissions
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

const int MX = 1e3 + 10;

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt[10] = {0}, dp[2][10];

        for (int i = 0; i < m; i++) cnt[grid[i][0]]++;
        for (int i = 0; i < 10; ++i) dp[0][i] = m - cnt[i];
        if (n == 1) return *min_element(dp[0], dp[0] + 10);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 10; ++j) cnt[j] = 0;
            for (int j = 0; j < m; j++) cnt[grid[j][i]]++;
            for (int j = 0; j < 10; j++) {
                dp[1][j] = m - cnt[j];
                int left = INT32_MAX;
                for (int k = 0; k < 10; k++) {
                    if (k == j) continue;
                    left = min(left, dp[0][k]);
                }
                dp[1][j] += left;
            }
            for (int j = 0; j < 10; j++) {
                dp[0][j] = dp[1][j];
            }
        }
        return *min_element(dp[1], dp[1] + 10);
    }
};