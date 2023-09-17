/**
 * Source: https://rb.gy/yzwus
 * Date: 2023/9/17
 * Skill:
 * Runtime: 19 ms, faster than 74.80% of C++ online submissions
 * Memory Usage: 9.6 MB, less than 81.65% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= graph.length <= 12
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
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size(), step = -1, final_state = 0;
        vector<vector<bool>> visited(n, vector<bool>(1<<n, false));
        deque<pairs> q;
        for (int i = 0; i < n; i++) {
            final_state += 1<<i;
            visited[i][1<<i] = true;
            q.push_back({i, 1<<i});
        }
        vector<unordered_set<int>> adj_set(n);
        for (int i = 0; i < n; ++i) {
            for (auto j: graph[i]) {
                adj_set[i].insert(j);
                adj_set[j].insert(i);
            }
        }
        while (!q.empty()) {
            int sz = q.size();
            step++;
            for (int i = 0; i < sz; ++i) {
                auto [pos, state] = q.front(); q.pop_front();
                if (state == final_state)
                    return step;
                for (auto j: adj_set[pos]) {
                    int next_state = state | (1<<j);
                    if (!visited[j][next_state]) {
                        visited[j][next_state] = true;
                        q.push_back({j, next_state});
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums{8,7,3,5,7,2,4,9};
    vector<vector<int>> arr{{0,1,0,0,0}, {0,1,0,1,0}, {0,0,0,1,0}};
}