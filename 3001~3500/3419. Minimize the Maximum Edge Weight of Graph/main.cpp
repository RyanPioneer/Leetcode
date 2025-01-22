/**
 * Source: ibit.ly/a1EIJ
 * Date: 2025/1/22
 * Skill:
 * Ref:
 * Runtime: 330 ms, faster than 61.27% of C++ online submissions
 * Memory Usage: 288.24 MB, less than 71.10% of C++ online submissions
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
typedef pair<int, int> PII;


class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        vector<vector<PII>> graph(n);
        for (auto& edge: edges) {
            graph[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<int> visited(n, 0);
        auto checkFeasible = [&](int idx) {
            fill(visited.begin(), visited.end(), 0);
            queue<int> q;
            q.push(0);
            visited[0] = 1;
            int total = 1;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (auto& [v, w]: graph[u]) {
                    if (w <= edges[idx][2] && !visited[v]) {
                        visited[v] = 1;
                        q.push(v);
                        total++;
                    }
                }
            }
            return total == n;
        };

        int lo = 0, hi = edges.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (checkFeasible(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return checkFeasible(lo) ? edges[lo][2] : -1;
    }
};
