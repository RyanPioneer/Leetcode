/**
 * Source: https://rb.gy/c053g
 * Date: 2023/9/10
 * Skill:
 * Runtime: 32 ms, faster than 71.43% of C++ online submissions
 * Memory Usage: 22.96 MB, less than 14.29% of C++ online submissions
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
    unordered_map<ll, int> state2step;
    ll final_state = 111111111;
public:
    int minimumMoves(vector<vector<int>>& grid) {
        ll state = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                state += grid[i][j] * pow(10, i * 3 + j);
        return dfs(state);
    }
    int dfs(int state) {
        if (state == final_state)
            return 0;
        if (state2step.find(state) != state2step.end())
            return state2step[state];
        int res = INT32_MAX;
        ll state1 = state;
        for (int i = 0; i < 9; i++) {
            if (state1 % 10 > 1) {
                int pos = 1, x = i / 3, y = i % 3, cur_len = pow(10, i);
                for (int j = 0; j < 9; j++) {
                    if (state / pos % 10 == 0) {
                        int xx = j / 3, yy = j % 3;
                        res = min(res, dfs(state - cur_len + pow(10, j)) + abs(x - xx) + abs(y - yy));
                    }
                    pos *= 10;
                }
            }
            state1 /= 10;
        }
        state2step[state] = res;
        return res;
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