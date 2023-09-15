/**
 * Source: https://rb.gy/cknp4
 * Date: 2023/9/15
 * Skill:
 * Runtime: 647 ms, faster than 48.98% of C++ online submissions
 * Memory Usage: 96.20 MB, less than 92.78% of C++ online submissions
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
        priority_queue<pairs, vector<pairs>, greater<pairs>> pq;
        pq.push(make_pair((grid[0][0] == 1), 0));
        while (!pq.empty()) {
            auto [num, pos] = pq.top(); pq.pop();
            if (pos == m * n - 1)
                return num;
            if (visited[pos])
                continue;
            visited[pos] = true;
            int x = pos / n, y = pos % n;
            for (int i = 0; i < 4; i++) {
                int xx = x + dir[i], yy = y + dir[i + 1];
                if (xx < 0 || xx >= m || yy < 0 || yy >= n || visited[xx * n + yy])
                    continue;
                pq.push(make_pair(num + (grid[xx][yy] == 1), xx * n + yy));
            }
        }
        return -1;
    }
};


int main() {
    Solution s;
    vector<int> nums{1,1,3,3};
    vector<vector<int>> arr{{0,1,1}, {1,1,0}, {1,1,0}};
    int res = s.minimumObstacles(arr);
    cout << res << endl;
}