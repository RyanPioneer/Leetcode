/**
 * Source: ibit.ly/E5ewb
 * Date: 2024/5/12
 * Skill:
 * Ref:
 * Runtime: 207 ms, faster than 14.29% of C++ online submissions
 * Memory Usage: 61.13 MB, less than 71.43% of C++ online submissions
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
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = INT32_MIN;
        int premin[MX][MX];
        fill(premin[0], premin[MX - 1] + MX, INT32_MAX / 2);
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int mi = min(premin[i - 1][j], premin[i][j - 1]);
                res = max(res, grid[i - 1][j - 1] - mi);
                premin[i][j] = min(mi, grid[i - 1][j - 1]);
            }
        }
        return res;
    }
};