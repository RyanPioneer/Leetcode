/*
 * @lc app=leetcode id=3558 lang=cpp
 *
 * [3558] Number of Ways to Assign Edge Weights I
 */

// @lc code=start
#define ll long long
const int MX = 1e9 + 7;
class Solution {
   public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        function<int(int, int)> dfs = [&](int node, int parent) {
            int d = 0;
            for (int neighbor : graph[node]) {
                if (neighbor != parent) {
                    d = max(d, dfs(neighbor, node));
                }
            }
            return d + 1;
        };

        int depth = dfs(0, -1) - 1;
        ll res = 1;
        for (int i = 1; i < depth; i++) {
            res = (res * 2) % MX;
        }

        return res;
    }
};
// @lc code=end
