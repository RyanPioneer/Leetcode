/**
 * Source: tinyurl.com/2dnkszp8
 * Date: 2025/7/26
 * Skill:
 * Ref:
 * Runtime: 70 ms, faster than 70.28% of C++ online submissions
 * Memory Usage: 192.06 MB, less than 97.86% of C++ online submissions
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
#define ll long long
const int MOD = 1e9 + 7;

class Solution {
   public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(i);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [time, u] = pq.top();
            pq.pop();
            if (time > dist[u]) continue;
            for (int i : graph[u]) {
                int v = edges[i][1];
                int start = edges[i][2];
                int end = edges[i][3];
                if (start > time) {
                    if (start + 1 < dist[v]) {
                        dist[v] = start + 1;
                        pq.push({start + 1, v});
                    }
                } else if (end >= time && time + 1 < dist[v]) {
                    dist[v] = time + 1;
                    pq.push({time + 1, v});
                }
            }
        }
        return dist[n - 1] == INT_MAX ? -1 : dist[n - 1];
    }
};
