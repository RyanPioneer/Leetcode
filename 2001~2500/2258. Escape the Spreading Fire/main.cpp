/**
 * Source: https://rb.gy/b265l
 * Date: 2023/9/11
 * Skill:
 * Runtime: 80 ms, faster than 67.96% of C++ online submissions
 * Memory Usage: 21.57 MB, less than 83.46% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      2 <= m, n <= 300
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
    int m, n;
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> dis(m, vector<int>(n, -1));
        vector<int> dirs{1, 0, -1, 0, 1};
        deque<pairs> q;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1) {
                    q.push_back(make_pair(i * n + j, 0));
                    dis[i][j] = 0;
                }

        while (!q.empty()) {
            auto [pos, dist] = q.front();
            q.pop_front();
            int x = pos / n, y = pos % n;
            for (int i = 0; i < 4; i++) {
                int xx = x + dirs[i], yy = y + dirs[i + 1];
                if (check_feasible(xx, yy) && grid[xx][yy] != 2 && dis[xx][yy] == -1) {
                    dis[xx][yy] = dist + 1;
                    q.push_back(make_pair(xx * n + yy, dist + 1));
                }
            }
        }

        vector<int> father(m * n);
        for (int i = 0; i < m * n; i++)
            father[i] = i;

        vector<bool> visited(m * n, false);
        visited[0] = true;
        priority_queue<pairs> pq;

        q.push_back(make_pair(0, 0));
        while (!q.empty()) {
            auto [pos, dist] = q.front();
            q.pop_front();
            int x = pos / n, y = pos % n;
            cout << x << " " << y << endl;
            if (dis[x][y] != -1 && ((dist >= dis[x][y] && pos != m * n - 1) || (dist > dis[x][y] && pos == m * n - 1))) {
                dis[x][y] = -1;
                continue;
            }
            if (dis[x][y] == -1)
                dis[x][y] = INT32_MAX / 2;
            else
                dis[x][y] -= dist + (pos != m * n - 1);
            pq.push(make_pair(dis[x][y], pos));
            for (int i = 0; i < 4; i++) {
                int xx = x + dirs[i], yy = y + dirs[i + 1];
                if (check_feasible(xx, yy) && grid[xx][yy] != 2 && !visited[xx * n + yy]) {
                    visited[xx * n + yy] = true;
                    q.push_back(make_pair(xx * n + yy, dist + 1));
                }
            }
        }

        if (dis[m - 1][n - 1] == -1)
            return -1;
        if (dis[m - 1][n - 1] > 2 * m * n)
            return 1e9;

        std::fill(visited.begin(), visited.end(), false);
        while (!pq.empty()) {
            auto [dist, pos] = pq.top();
            visited[pos] = true;
            pq.pop();
            int x = pos / n, y = pos % n;
            for (int i = 0; i < 4; i++) {
                int xx = x + dirs[i], yy = y + dirs[i + 1], pos2 = xx * n + yy;
                if (check_feasible(xx, yy) && visited[pos2]) {
                    union_set(pos, pos2, father);
                }
            }
            if (find_father(0, father) == find_father(m * n - 1, father))
                return (dist < 2 * m * n) ? dist : 1e9;
        }
        return -1;
    }
    bool check_feasible(int x, int y) {
        return (0 <= x && x < m && 0 <= y && y < n);
    }
    int find_father(int x, vector<int>& father) {
        if (father[x] != x)
            father[x] = find_father(father[x], father);
        return father[x];
    }
    void union_set(int x, int y, vector<int>& father) {
        int x_father = find_father(x, father), y_father = find_father(y, father);
        if (x_father != y_father)
            father[x_father] = y_father;
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
    int res = s.maximumMinutes(grid);
    cout << res << endl;
}