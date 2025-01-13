/**
 * Source: ibit.ly/5saK3
 * Date: 2025/1/13
 * Skill:
 * Ref:
 * Runtime: 335 ms, faster than 62.40% of C++ online submissions
 * Memory Usage: 334.79 MB, less than 84.16% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      2 <= n, m <= 10 ** 5
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
const int MX = 1e5+1;


class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1, nodeDis[MX];
        vector<vector<int>> graph1(n), graph2(m);
        for (auto& e : edges1) {
            graph1[e[0]].push_back(e[1]);
            graph1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2) {
            graph2[e[0]].push_back(e[1]);
            graph2[e[1]].push_back(e[0]);
        }

        auto helper = [&](int idx, int sz, vector<vector<int>>&graph) {
            for (int i = 0; i < sz; i++) {
                nodeDis[i] = -1;
            }
            nodeDis[idx] = 0;
            vector<int> cnt(2, 0);
            cnt[0] = 1;
            queue<int> q;
            q.push(idx);
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int next : graph[node]) {
                    if (nodeDis[next] == -1) {
                        nodeDis[next] = nodeDis[node] + 1;
                        q.push(next);
                        cnt[nodeDis[next] % 2]++;
                    }
                }
            }
            return cnt;
        };

        vector<int> cnt = helper(0, m, graph2);
        int num2 = max(cnt[0], cnt[1]);

        cnt = helper(0, n, graph1);
        vector<int> res(n, -1);
        res[0] = cnt[0] + num2;
        for (int i = 0; i < n; i++) {
            nodeDis[i] = -1;
        }
        nodeDis[0] = cnt[0];
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int next : graph1[node]) {
                if (nodeDis[next] == -1) {
                    nodeDis[next] = n - nodeDis[node];
                    q.push(next);
                    res[next] = nodeDis[next] + num2;
                }
            }
        }
        return res;
    }
};
