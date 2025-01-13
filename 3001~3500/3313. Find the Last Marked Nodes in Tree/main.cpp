/**
 * Source: ibit.ly/2X0yx
 * Date: 2025/1/3
 * Skill:
 * Ref: ibit.ly/fNga7
 * Runtime: 239 ms, faster than 85.00% of C++ online submissions
 * Memory Usage: 282.67 MB, less than 90.00% of C++ online submissions
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


class Solution {
public:
    vector<int> lastMarkedNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> grph(n);
        for (auto& e : edges) {
            grph[e[0]].push_back(e[1]);
            grph[e[1]].push_back(e[0]);
        }
        auto find_farthest_node = [&](int node) {
            int last;
            vector<bool> visited(n, false);
            visited[node] = true;
            queue<int> q;
            q.push(node);
            while (!q.empty()) {
                int cur = q.front();
                last = cur;
                q.pop();
                for (int nxt : grph[cur]) {
                    if (!visited[nxt]) {
                        visited[nxt] = true;
                        q.push(nxt);
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
                        dist[nxt] = dist[cur] + 1;
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
            res[i] = dist1[i] > dist2[i] ? v1 : v2;
        }
        return res;
    }
};
