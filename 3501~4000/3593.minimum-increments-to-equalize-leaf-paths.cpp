/*
 * @lc app=leetcode id=3593 lang=cpp
 *
 * [3593] Minimum Increments to Equalize Leaf Paths
 */

// @lc code=start
#define ll long long
class Solution {
   public:
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        int res = 0;
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        function<ll(int, int)> dfs = [&](int node, int parent) {
            ll mx = -1, total = 0, cnt = 0;
            for (auto& neighbor : graph[node]) {
                if (neighbor == parent) continue;
                ll num = dfs(neighbor, node);
                total++;
                if (num > mx) {
                    mx = num;
                    cnt = 1;
                } else if (num == mx) {
                    cnt++;
                }
            }
            res += total - cnt;
            return cost[node] + mx;
        };

        dfs(0, -1);
        return res;
    }
};
// @lc code=end
