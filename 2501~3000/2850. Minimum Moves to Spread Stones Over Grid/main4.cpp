/**
 * Source: https://rb.gy/c053g
 * Date: 2023/9/10
 * Skill:
 * Runtime: 7 ms, faster than 100% of C++ online submissions
 * Memory Usage: 18.6 MB, less than 85.71% of C++ online submissions
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

using namespace std;

#define ll long long

typedef pair<int, int> pairs;


class Solution {
    int res = INT32_MAX;
public:
    int minimumMoves(vector<vector<int>>& grid) {
        dfs(0, grid);
        return res;
    }
    void dfs(int cur_step, vector<vector<int>>& grid) {
        int pos = -1;
        for (int i = 0; i < 9; i++)
            if (grid[i / 3][i % 3] == 0) {
                pos = i;
                break;
            }

        if (pos == -1) {
            res = min(res, cur_step);
            return;
        }

        int x = pos / 3, y = pos % 3;
        grid[x][y] = 1;
        for (int i = 0; i < 9; i++)
            if (grid[i / 3][i % 3] > 1) {
                grid[i / 3][i % 3]--;
                int xx = i / 3, yy = i % 3;
                dfs(cur_step + abs(x - xx) + abs(y - yy), grid);
                grid[i / 3][i % 3]++;
            }
        grid[x][y] = 0;
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
}