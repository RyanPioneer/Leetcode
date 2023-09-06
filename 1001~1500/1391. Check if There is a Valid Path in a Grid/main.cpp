/**
 * Source: https://rb.gy/tbnu9
 * Date: 2023/9/6
 * Skill:
 * Runtime: 143 ms, faster than 54.88% of C++ online submissions
 * Memory Usage: 58.36 MB, less than 67.89% of C++ online submissions
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
        vector<unordered_set<int>> dirs(4); // up, down, left, right
        dirs[0].insert({2, 3, 4});
        dirs[1].insert({2, 5, 6});
        dirs[2].insert({1, 4, 6});
        dirs[3].insert({1, 3, 5});
        q.push_back(make_pair(0, 0));
        visited[0][0] = true;
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop_front();
            if (x == m - 1 && y == n - 1)
                return true;
            if (check_feasible(x - 1, y) && !visited[x - 1][y] &&
                (grid[x][y] == 2 || grid[x][y] == 5 || grid[x][y] == 6)
                && dirs[0].find(grid[x - 1][y]) != dirs[0].end()) {
                visited[x - 1][y] = true;
                q.push_back(make_pair(x - 1, y));
            }
            if (check_feasible(x + 1, y) && !visited[x + 1][y] &&
                (grid[x][y] == 2 || grid[x][y] == 3 || grid[x][y] == 4)
                && dirs[1].find(grid[x + 1][y]) != dirs[1].end()) {
                visited[x + 1][y] = true;
                q.push_back(make_pair(x + 1, y));
            }
            if (check_feasible(x, y - 1) && !visited[x][y - 1] &&
                (grid[x][y] == 1 || grid[x][y] == 3 || grid[x][y] == 5)
                && dirs[2].find(grid[x][y - 1]) != dirs[2].end()) {
                visited[x][y - 1] = true;
                q.push_back(make_pair(x, y - 1));
            }
            if (check_feasible(x, y + 1) && !visited[x][y + 1] &&
                (grid[x][y] == 1 || grid[x][y] == 4 || grid[x][y] == 6)
                && dirs[3].find(grid[x][y + 1]) != dirs[3].end()) {
                visited[x][y + 1] = true;
                q.push_back(make_pair(x, y + 1));
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