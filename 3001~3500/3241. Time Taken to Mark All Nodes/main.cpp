/**
 * Source: ibit.ly/03y8P
 * Date: 2025/1/4
 * Skill:
 * Ref: 
 * Runtime: 354 ms, faster than 71.05% of C++ online submissions
 * Memory Usage: 341.25 MB, less than 65.79% of C++ online submissions
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

#define MK make_pair 

using namespace std;
typedef pair<int, int> PII;


class Solution {
public:
    vector<int> timeTaken(vector<vector<int> >& edges) {
        int n = edges.size() + 1;
        vector<vector<int> > grph(n);
        for (auto& e : edges) {
            grph[e[0]].push_back(e[1]);
            grph[e[1]].push_back(e[0]);
        }
        auto find_farthest_node = [&](int node) {
            int last, cnt = node % 2 ? 0 : 1;
            vector<bool> visited(n, false);
            visited[node] = true;
            queue<PII> q;
            q.push(MK(node, cnt));
            while (!q.empty()) {
                int sz = q.size();
                while (sz--) {
                    auto [cur, cnt] = q.front();
                    q.pop();
                    if (cnt == 1) {
                        q.push(MK(cur, 0));
                        continue;
                    }
                    last = cur;
                    for (int nxt : grph[cur]) {
                        if (!visited[nxt]) {
                            visited[nxt] = true;
                            cnt = nxt % 2 ? 0 : 1;
                            q.push(MK(nxt, cnt));
                        }
                    }
                }
            }
            return last;   
        };

        int v1 = find_farthest_node(0);
        int v2 = find_farthest_node(v1);

        auto calculate_distance = [&](int node) {
            vector<int> dist(n, -1);
            dist[node] = 0;
            queue<int> q;
            q.push(node);
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                for (int nxt : grph[cur]) {
                    if (dist[nxt] == -1) {
                        dist[nxt] = dist[cur] + 1 + (nxt + 1) % 2;
                        q.push(nxt);
                    }
                }
            }
            return dist;
        };

        vector<int> dist1 = calculate_distance(v1);
        vector<int> dist2 = calculate_distance(v2);
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = max(dist1[i] + (v1 + 1) % 2, dist2[i] + (v2 + 1) % 2) - (i + 1) % 2;
        }
        return res;
    }
};
