/**
 * Source: https://rb.gy/c053g
 * Date: 2023/9/10
 * Skill:
 * Runtime: 4 ms, faster than 100% of C++ online submissions
 * Memory Usage: 18.9 MB, less than 57.14% of C++ online submissions
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
    ll final_state = 111111111;
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int state = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid.size(); j++)
                state += grid[i][j] * pow(10, 3 * i + j);

        dfs(0, state);
        return res;
    }
    void dfs(int cur_step, int state) {
        if (state == final_state) {
            res = min(res, cur_step);
            return;
        }
        int pos = -1, num = 1;
        for (int i = 0; i < 9; i++) {
            if (state / num % 10 == 0) {
                pos = i;
                break;
            }
            num *= 10;
        }
        int x = pos / 3, y = pos % 3;
        int next_state = state + pow(10, pos);
        num = 1;
        for (int i = 0; i < 9; i++) {
            if (state / num % 10 > 1) {
                int xx = i / 3, yy = i % 3;
                dfs(cur_step + abs(x - xx) + abs(y - yy), next_state - pow(10, i));
            }
            num *= 10;
        }
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