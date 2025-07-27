/**
 * Source: tinyurl.com/22kvs3kv
 * Date: 2025/7/27
 * Skill:
 * Ref:
 * Runtime: 166 ms, faster than 58.73% of C++ online submissions
 * Memory Usage: 217.79 MB, less than 95.47% of C++ online submissions
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
const int MOD = 1e9 + 7, MX = 251;

class Solution {
   public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        vector<int> par(n, 0);
        iota(par.begin(), par.end(), 0);
        sort(edges.begin(), edges.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[3] != b[3]) return a[3] > b[3];
                 return a[2] > b[2];
             });

        vector<int> doubleEdges;

        function<int(int)> find = [&](int x) {
            if (par[x] != x) par[x] = find(par[x]);
            return par[x];
        };

        function<void(int, int)> unionSets = [&](int x, int y) {
            x = find(x);
            y = find(y);
            if (x != y) {
                par[y] = x;
            }
        };

        int edgeNum = 0, res = INT_MAX;
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            if (e[3]) {
                if (find(u) == find(v)) return -1;
                unionSets(u, v);
                res = min(res, e[2]);
                edgeNum++;
            } else if (find(u) != find(v)) {
                edgeNum++;
                unionSets(u, v);
                doubleEdges.push_back(e[2]);
            }
        }

        if (edgeNum < n - 1) return -1;

        sort(begin(doubleEdges), end(doubleEdges));
        for (int i = 0; i < doubleEdges.size() && k > 0; i++, k--) {
            doubleEdges[i] *= 2;
        }
        return doubleEdges.empty() ? res
                                   : min(res, *min_element(doubleEdges.begin(),
                                                           doubleEdges.end()));
    }
};
