/**
 * Source: t.ly/_IsWF
 * Date: 2025/1/27
 * Skill:
 * Ref:
 * Runtime: 19 ms, faster than 73.56% of C++ online submissions
 * Memory Usage: 28.93 MB, less than 71.11% of C++ online submissions
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
typedef array<int, 3> AI3;
const int MOD = 1e9+7;


class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        priority_queue<AI3, std::vector<AI3>, std::greater<AI3>> minHeap;
        minHeap.push({0, 0, 0});
        moveTime[0][0] = -1;

        while (!minHeap.empty()) {
            auto [t, x, y] = minHeap.top();
            minHeap.pop();

            for (auto &dir: dirs) {
                int dx = dir.first, dy = dir.second;
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && moveTime[nx][ny] != -1) {
                    if (nx == n - 1 && ny == m - 1) {
                        return max(t, moveTime[nx][ny]) + 1;
                    }
                    minHeap.push({max(t, moveTime[nx][ny]) + 1, nx, ny});
                    moveTime[nx][ny] = -1;
                }
            }
        }
        return -1;
    }
};
