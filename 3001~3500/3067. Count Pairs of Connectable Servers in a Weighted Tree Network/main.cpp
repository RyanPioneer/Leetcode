/**
 * Source: is.gd/uu3j9S
 * Date: 2024/3/3
 * Skill:
 * Ref:
 * Runtime: 315 ms, faster than 36.36% of C++ online submissions
 * Memory Usage: 39.52 MB, less than 45.45% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      2 <= n <= 1000
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

const int MX = 1e3+10;


class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;
        vector<int> res(n, 0);
        vector<vector<int>> adj_list[MX];
        for (auto &e: edges) {
            adj_list[e[0]].push_back({e[1], e[2]});
            adj_list[e[1]].push_back({e[0], e[2]});
        }

        function<int(int, int, int)>dfs = [&](int cur, int par, int dis) {
            int num = dis % signalSpeed == 0 ? 1 : 0;
            for (auto &e: adj_list[cur]) {
                if (e[0] == par) continue;
                num += dfs(e[0], cur, dis + e[1]);
            }
            return num;
        };

        for (int i = 0; i < n; i++) {
            int total = 0;
            for (auto &e: adj_list[i]) {
                int num = dfs(e[0], i, e[1]);
                res[i] += total * num;
                total += num;
            }
        }
        return res;
    }
};