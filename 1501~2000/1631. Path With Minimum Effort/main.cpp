/**
 * Source: https://rb.gy/xibtg
 * Date: 2023/9/16
 * Skill:
 * Runtime: 110 ms, faster than 69.39% of C++ online submissions
 * Memory Usage: 19.13 MB, less than 96.78% of C++ online submissions
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
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size(), dir[5] = {0, 1, 0, -1, 0};
        vector<bool> visited(m * n, false);
        priority_queue<pairs, vector<pairs>, greater<pairs>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [effort, pos] = pq.top(); pq.pop();
            if (pos == m * n - 1)
                return effort;
            if (visited[pos])
                continue;
            visited[pos] = true;
            int x = pos / n, y = pos % n;
            for (int i = 0; i < 4; i++) {
                int xx = x + dir[i], yy = y + dir[i + 1], pos2 = xx * n + yy;
                if (xx < 0 || xx >= m || yy < 0 || yy >= n || visited[pos2])
                    continue;
                pq.push({max(effort, abs(heights[x][y] - heights[xx][yy])), pos2});
            }
        }
        return 0;
    }
};


int main() {
    Solution s;
    vector<int> nums{1,1,3,3};
    vector<vector<int>> arr{{0,1,1}, {1,1,0}, {1,1,0}};
}