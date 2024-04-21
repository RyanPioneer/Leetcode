/**
 * Source: is.gd/v3uDza
 * Date: 2024/4/21
 * Skill:
 * Ref:
 * Runtime: 528 ms, faster than 71.43% of C++ online submissions
 * Memory Usage: 220.59 MB, less than 14.29% of C++ online submissions
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
const int MX = 5e4 + 10;

class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        map<ll, int> mp;
        vector<unordered_set<int>> par(n);
        vector<vector<PII>> graph(n);
        vector<int> dis(n, INT32_MAX / 2);
        vector<bool> res(edges.size(), false);

        for (int i = 0; i < edges.size(); i++) {
            vector<int> &e = edges[i];
            graph[e[0]].emplace_back(e[1], e[2]);
            graph[e[1]].emplace_back(e[0], e[2]);
            ll a = min(e[0], e[1]);
            ll b = max(e[0], e[1]);
            mp[a * MX + b] = i;
        }

        priority_queue<PII, vector<PII>, greater<>> pq;

        pq.push({0, 0});
        dis[0] = 0;

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            for (auto &[i, j]: graph[node]) {
                if (d + j > dis[i]) {
                    continue;
                } else if (d + j == dis[i]) {
                    par[i].insert(node);
                } else {
                    par[i].clear();
                    dis[i] = d + j;
                    par[i].insert(node);
                    pq.push({dis[i], i});
                }
            }
        }

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(n - 1);
        visited[n - 1] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto &i: par[cur]) {
                ll a = min(cur, i);
                ll b = max(cur, i);
                int idx = mp[a * MX + b];
                res[idx] = true;
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        return res;
    }
};