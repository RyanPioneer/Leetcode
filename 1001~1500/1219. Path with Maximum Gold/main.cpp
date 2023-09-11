/**
 * Source: https://rb.gy/pc7yj
 * Date: 2023/9/11
 * Skill:
 * Runtime: 172 ms, faster than 93.21% of C++ online submissions
 * Memory Usage: 7.37 MB, less than 93.81% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= m, n <= 15
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;

typedef unsigned long long ULL;
typedef pair<ULL, ULL> PULL;

class Solution {
    int res = 0, m, n;
    int dirs[5] = {0, 1, 0, -1, 0};
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] > 0) {
                    int num = grid[i][j];
                    grid[i][j] = 0;
                    backtracking(i, j, grid, num);
                    grid[i][j] = num;
                }
        return res;
    }
    void backtracking(int x, int y, vector<vector<int>>& grid, int cur_sum) {
        for (int i = 0; i < 4; ++i) {
            int xx = x + dirs[i], yy = y + dirs[i + 1];
            if (check_feasible(xx, yy) && grid[xx][yy] > 0) {
                int num = grid[xx][yy];
                grid[xx][yy] = 0;
                backtracking(xx, yy, grid, cur_sum + num);
                grid[xx][yy] = num;
            }
        }
        res = max(res, cur_sum);
    }
    bool check_feasible(int x, int y) {
        return 0 <= x && x < m && 0 <= y && y < n;
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
    vector<vector<int>> grid{{0,2,0,0,0,0,0},{0,0,0,2,2,1,0},{0,2,0,0,1,2,0},{0,0,2,2,2,0,2},{0,0,0,0,0,0,0}};
}