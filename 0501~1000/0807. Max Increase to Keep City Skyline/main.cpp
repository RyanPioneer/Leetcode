/**
 * Source: t.ly/_v5ex
 * Date: 2024/6/2
 * Skill:
 * Ref:
 * Runtime: 4 ms, faster than 76.91% of C++ online submissions
 * Memory Usage: 12.67 MB, less than 26.02% of C++ online submissions
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
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0;
        vector<int> rows(n, 0), cols(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rows[i] = max(rows[i], grid[i][j]);
                cols[j] = max(cols[j], grid[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int mx = min(rows[i], cols[j]);
                res += max(0, mx - grid[i][j]);
            }
        }
        return res;
    }
};