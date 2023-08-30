/**
 * Source: https://rb.gy/bz9rs
 * Date: 2023/8/30
 * Skill:
 * Runtime: 319 ms, faster than 61.02% of C++ online submissions
 * Memory Usage: 108.22 MB, less than 67.55% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= m, n <= 1000
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <queue>

using namespace std;

#define ll long long
// using ll = long long;


class Solution {
public:
    bool check_feasible(int x, int y, int m, int n) {
        return 0 <= x && x < m && 0 <= y && y < n;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<int> dirs{0, 1, 0, -1, 0};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    isWater[i][j] = 0;
                    q.push({i, j});
                } else
                    isWater[i][j] = -1;
            }
        }
        while (!q.empty()) {
            auto vec = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                if (check_feasible(vec.first + dirs[i], vec.second + dirs[i + 1], m, n) &&
                    isWater[vec.first + dirs[i]][vec.second + dirs[i + 1]] == -1) {
                    isWater[vec.first + dirs[i]][vec.second + dirs[i + 1]] = isWater[vec.first][vec.second] + 1;
                    q.push({vec.first + dirs[i], vec.second + dirs[i + 1]});
                }
            }
        }
        return isWater;
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
    vector<int> tasks{1,2,3,1};
}