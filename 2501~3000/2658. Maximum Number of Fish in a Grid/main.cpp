/**
 * Source: twtr.to/-uwAF
 * Date: 2023/10/18
 * Skill:
 * Runtime: 37 ms, faster than 96.59% of C++ online submissions
 * Memory Usage: 89.14 MB, less than 72.60% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
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
#include <bitset>
#include <functional>

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int res = 0, m = grid.size(), n = grid[0].size(), dir[5] = {0, 1, 0, -1, 0};
        function<bool(int, int)> check;
        function<int(int, int)> dfs;
        check = [=](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };
        dfs = [&](int x, int y) {
            if (grid[x][y] == 0)
                return 0;
            int num = grid[x][y];
            grid[x][y] = 0;
            for (int i = 0; i < 4; i++) {
                int xx = x + dir[i], yy = y + dir[i + 1];
                if (!check(xx, yy) || grid[xx][yy] == 0)
                    continue;
                num += dfs(xx, yy);
            }
            return num;
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0)
                    res = max(res, dfs(i, j));
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}