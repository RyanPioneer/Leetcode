/**
 * Source: t.ly/HMOdi
 * Date: 2025/4/3
 * Skill:
 * Ref:
 * Runtime: 9 ms, faster than 83.67% of C++ online submissions
 * Memory Usage: 37.33 MB, less than 61.73% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */

#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination)
    {
        vector<vector<int>> g(n);
        for (const auto& e : edges) {
            g[e[0]].push_back(e[1]);
        }

        vector<int> visited(n, 0);
        function<bool(int)> dfs = [&](int node) {
            if (g[node].empty()) {
                return node == destination;
            }
            if (visited[node] == 2) {
                return true;
            }
            if (visited[node] == 1) {
                return false;
            }
            visited[node] = 1;
            for (const auto& next : g[node]) {
                if (visited[next] == 0) {
                    if (!dfs(next)) {
                        return false;
                    }
                } else if (visited[next] == 1) {
                    return false;
                }
            }
            visited[node] = 2;
            return true;
        };
        return dfs(source);
    }
};
