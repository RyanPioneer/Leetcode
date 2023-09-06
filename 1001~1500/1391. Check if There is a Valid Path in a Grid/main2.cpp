/**
 * Source: https://rb.gy/tbnu9
 * Date: 2023/9/6
 * Skill:
 * Runtime: 135 ms, faster than 57.32% of C++ online submissions
 * Memory Usage: 58.19 MB, less than 70.73% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= m, n <= 300
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
    int m, n;
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, false));
        deque<pairs> q;
        vector<vector<pairs>> dirs = {
                {{0, 1}, {0, -1}},
                {{1, 0}, {-1, 0}},
                {{1, 0}, {0, -1}},
                {{1, 0}, {0, 1}},
                {{-1, 0}, {0, -1}},
                {{-1, 0}, {0, 1}}
        };
        q.push_back(make_pair(0, 0));
        visited[0][0] = true;
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop_front();
            if (x == m - 1 && y == n - 1)
                return true;
            for (int i = 0; i < 2; i++) {
                int next_x = x + dirs[grid[x][y] - 1][i].first, next_y = y + dirs[grid[x][y] -1][i].second;
                if (!check_feasible(next_x, next_y) || visited[next_x][next_y])
                    continue;
                for (int j = 0; j < 2; j++) {
                    int xx = next_x + dirs[grid[next_x][next_y] - 1][j].first, yy = next_y + dirs[grid[next_x][next_y] - 1][j].second;
                    if (xx == x && yy == y) {
                        q.push_back(make_pair(next_x, next_y));
                        visited[next_x][next_y] = true;
                    }
                }
            }
        }
        return false;
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
//    Solution s;
    pairs p = make_pair(1, 2);
    set<pairs> myset;
    myset.insert(p);
    if (myset.find(make_pair(1, 2)) != myset.end())
        cout << "true" << endl;
    else
        cout << "false" << endl;
}