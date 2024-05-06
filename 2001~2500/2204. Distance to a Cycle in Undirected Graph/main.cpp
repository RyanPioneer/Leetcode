/**
 * Source: t.ly/kkkfx
 * Date: 2024/5/6
 * Skill:
 * Ref:
 * Runtime: 781 ms, faster than 19.15% of C++ online submissions
 * Memory Usage: 147.01 MB, less than 46.81% of C++ online submissions
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
    vector<int> distanceToCycle(int n, vector<vector<int>>& edges) {
        unordered_set<int> cycle;
        vector<vector<int>> graph(n);
        for (auto &e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<int> visited(n, false);

        function<int(int, int)> dfs = [&](int cur, int par) {
            int num = -1;
            for (auto &i: graph[cur]) {
                if (i == par) continue;
                if (!visited[i]) {
                    visited[i] = true;
                    int j = dfs(i, cur);
                    if (j != -1) num = j;
                } else if (num == -1) {
                    num = i;
                }
            }
            if (num != -1) cycle.insert(cur);
            if (num == cur) num = -1;
            // cout << cur << " " << num << endl;
            return num;
        };

        visited[0] = true;
        dfs(0, -1);

        vector<int> res(n, -1);
        queue<int> q;
        for (auto &i: cycle) {
            q.push(i);
            res[i] = 0;
        }
        int dis = 0;
        while (!q.empty()) {
            int sz = q.size();
            dis++;
            while (sz--) {
                int node = q.front();
                q.pop();
                for (auto &i: graph[node]) {
                    if (res[i] == -1) {
                        res[i] = dis;
                        q.push(i);
                    }
                }
            }
        }
        return res;
    }
};