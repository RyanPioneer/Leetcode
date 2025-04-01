/**
 * Source: t.ly/57PwX
 * Date: 2025/1/27
 * Skill:
 * Ref:
 * Runtime: 67 ms, faster than 98.15% of C++ online submissions
 * Memory Usage: 82.02 MB, less than 99.18% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>
#include <functional>
#include <list>


using namespace std;
#define ll long long
typedef array<int, 4> AI4;
const int MOD = 1e9+7;


class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        priority_queue<AI4, std::vector<AI4>, std::greater<AI4>> minHeap;
        minHeap.push({0, 1, 0, 0});
        moveTime[0][0] = -1;

        while (!minHeap.empty()) {
            auto [t, step, x, y] = minHeap.top();
            minHeap.pop();

            for (auto &dir: dirs) {
                int dx = dir.first, dy = dir.second;
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && moveTime[nx][ny] != -1) {
                    if (nx == n - 1 && ny == m - 1) {
                        return max(t, moveTime[nx][ny]) + step;
                    }
                    minHeap.push({max(t, moveTime[nx][ny]) + step, 3 - step, nx, ny});
                    moveTime[nx][ny] = -1;
                }
            }
        }
        return -1;
    }
};
