/**
 * Source: t.ly/y09-v
 * Date: 2025/7/25
 * Skill:
 * Ref:
 * Runtime: 98 ms, faster than 72.28% of C++ online submissions
 * Memory Usage: 206.34 MB, less than 93.31% of C++ online submissions
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
    int minCost(int n, vector<vector<int>>& edges, int k) {
        int cnt = n;
        vector<int> par(n);
        iota(par.begin(), par.end(), 0);
        sort(edges.begin(), edges.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });

        function<int(int)> findParent = [&](int num) {
            if (par[num] != num) {
                par[num] = findParent(par[num]);
            }
            return par[num];
        };

        auto unionSets = [&](int a, int b) {
            int rootA = findParent(a);
            int rootB = findParent(b);
            if (rootA != rootB) {
                par[rootA] = rootB;
                cnt--;
            }
        };

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], cost = edge[2];
            if (findParent(u) != findParent(v)) {
                unionSets(u, v);
                if (cnt == k) {
                    return cost;
                }
            }
        }
        return 0;
    }
};