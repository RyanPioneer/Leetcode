/*
 * @lc app=leetcode id=3620 lang=cpp
 *
 * [3620] Network Recovery Pathways
 */

// @lc code=start
#define ll long long
class Solution {
   public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {
        this->n = online.size();
        this->online = &online;
        graph.assign(n, {});
        mx = 0;

        for (const auto& edge : edges) {
            graph[edge[0]].push_back({edge[1], (ll)edge[2]});
            mx = max(mx, (int)edge[2]);
        }

        int lo = 0, hi = mx;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (canAchieve(mid, k)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return canAchieve(lo, k) ? lo : -1;
    }

   private:
    int n, mx;
    vector<vector<pair<int, ll>>> graph;
    vector<bool>* online;
    vector<ll> dist;

    bool canAchieve(int mid, ll k) {
        dist.assign(n, LLONG_MAX);
        dist[0] = 0;
        using P = pair<ll, int>;  // {distance, node}
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;
            for (const auto& [v, w] : graph[u]) {
                if (!(*online)[v] || w < mid) continue;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[n - 1] <= k;
    }
};
// @lc code=end
