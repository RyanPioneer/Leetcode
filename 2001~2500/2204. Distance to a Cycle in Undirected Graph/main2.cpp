/**
 * Source: t.ly/kkkfx
 * Date: 2024/5/6
 * Skill:
 * Ref:
 * Runtime: 215 ms, faster than 79.79% of C++ online submissions
 * Memory Usage: 102.52 MB, less than 81.91% of C++ online submissions
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
        vector<int> res(n, 0), deg(n, 0);
        vector<vector<int>> graph(n);
        for (auto &e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            deg[e[0]]++;
            deg[e[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 1) {
                q.push(i);
                res[i] = -1;
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto &i: graph[cur]) {
                deg[i]--;
                if (deg[i] == 1) {
                    q.push(i);
                    res[i] = -1;
                }
            }
        }
        while (!q.empty()) q.pop();
        for (int i = 0; i < n; i++) {
            if (res[i] == 0) {
                q.push(i);
            }
        }
        int dis = 0;
        while (!q.empty()) {
            dis++;
            int sz = q.size();
            while (sz--) {
                int cur = q.front();
                q.pop();
                for (auto &i: graph[cur]) {
                    if (res[i] == -1) {
                        q.push(i);
                        res[i] = dis;
                    }
                }
            }
        }
        return res;
    }
};