/**
 * Source: https://rb.gy/c053g
 * Date: 2023/9/10
 * Skill:
 * Runtime: 155 ms, faster than 42.86% of C++ online submissions
 * Memory Usage: 41.84 MB, less than 14.29% of C++ online submissions
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
    unordered_map<int, bool> visited;
    vector<int> dirs{-1, 0, 1, 0, -1};
    int final_state = 111111111;
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int cur_state = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                cur_state += grid[i][j] * pow(10, i * 3 + j);
        visited[cur_state] = true;
        deque<int> q;
        int res = -1;
        q.push_back(cur_state);
        while (!q.empty()) {
            res++;
            int sz = q.size();
            for (int u = 0; u < sz; u++) {
                int state = q.front();
                q.pop_front();
                if (state == final_state)
                    return res;
                int state1 = state;
                for (int i = 0; i < 9; i++) {
                    if (state1 % 10 > 1) {
                        for (int k = 0; k < 4; k++) {
                            int next_x = i / 3 + dirs[k], next_y = i % 3 + dirs[k + 1];
                            if (check_feasible(next_x, next_y)) {
                                int next_state = state - pow(10, i) + pow(10, next_x * 3 + next_y);
                                if (next_state == final_state)
                                    return res + 1;
                                else if (visited.find(next_state) == visited.end()) {
                                    visited[next_state] = true;
                                    q.push_back(next_state);
                                }
                            }
                        }
                    }
                    state1 /= 10;
                }
            }
        }
        return res;
    }
    bool check_feasible(int x, int y) {
        return 0 <= x && x < 3 && 0 <= y && y < 3;
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