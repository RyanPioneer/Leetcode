/**
 * Source: t.ly/rWogj
 * Date: 2024/6/7
 * Skill:
 * Ref:
 * Runtime: 372 ms, faster than 41.24% of C++ online submissions
 * Memory Usage: 86.77 MB, less than 49.48% of C++ online submissions
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


const int MX = 1e3+7;


class Solution {
public:
    vector<int> closestNode(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        int visited[MX];
        vector<int> graph[MX], res;
        unordered_set<int> nodes;
        for (auto &e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        function<bool(int, int, int)> dfs = [&](int cur, int par, int target) {
            if (cur == target) {
                nodes.insert(cur);
                return true;
            }
            bool found = false;
            for (auto &i: graph[cur]) {
                if (i == par) continue;
                if (dfs(i, cur, target)) {
                    found = true;
                    break;
                }
            }
            if (found) nodes.insert(cur);
            return found;
        };

        for (auto &i: query) {
            fill(visited, visited + n, 0);
            nodes.clear();
            dfs(i[0], -1, i[1]);
            if (nodes.find(i[2]) != end(nodes)) {
                res.push_back(i[2]);
                continue;
            }
            queue<int> q;
            q.push(i[2]);
            visited[i[2]] = 1;
            bool found = false;
            while (!q.empty() && !found) {
                int cur = q.front();
                q.pop();
                for (auto &j: graph[cur]) {
                    if (visited[j]) continue;
                    if (nodes.find(j) != end(nodes)) {
                        res.push_back(j);
                        found = true;
                        break;
                    }
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
        return res;
    }
};