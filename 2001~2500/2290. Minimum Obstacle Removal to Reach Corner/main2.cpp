/**
 * Source: https://rb.gy/cknp4
 * Date: 2023/9/15
 * Skill:
 * Runtime: 222 ms, faster than 99.40% of C++ online submissions
 * Memory Usage: 108.55 MB, less than 58.73% of C++ online submissions
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
typedef unsigned long long ULL;
typedef pair<ULL, ULL> PULL;


class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dir[5] = {0, 1, 0, -1, 0};
        vector<int> visited(m * n, false);
        visited[0] = true;
        deque<pairs> q;
        q.push_back(make_pair(0, 0));
        while (!q.empty()) {
            auto [pos, num] = q.front(); q.pop_front();
            int x = pos / n, y = pos % n;
            for (int i = 0; i < 4; i++) {
                int xx = x + dir[i], yy = y + dir[i + 1], pos2 = xx * n + yy;
                if (xx < 0 || xx >= m || yy < 0 || yy >= n || visited[pos2])
                    continue;
                if (pos2 == m * n - 1)
                    return num;
                visited[pos2] = true;
                if (grid[xx][yy])
                    q.push_back(make_pair(pos2, num + 1));
                else
                    q.push_front(make_pair(pos2, num));
            }
        }
        return 0;
    }
};


int main() {
    Solution s;
    vector<int> nums{1,1,3,3};
    vector<vector<int>> arr{{0,1,1}, {1,1,0}, {1,1,0}};
    int res = s.minimumObstacles(arr);
    cout << res << endl;
}