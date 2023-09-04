/**
 * Source: https://rb.gy/h9pct
 * Date: 2023/9/3
 * Skill:
 * Runtime: 124 ms, faster than 85.26% of C++ online submissions
 * Memory Usage: 71.24 MB, less than 65.20% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <set>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;


class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        res.resize(n);
        vector<unordered_set<int>> adj_set(n);
        for (auto e: edges)
            adj_set[e[0]].insert(e[1]);
        for (int i = 0; i < n; i++)
            dfs(i, i, adj_set);
        return res;
    }
    void dfs(int root, int cur, vector<unordered_set<int>>& adj_set) {
        for (auto adj: adj_set[cur]) {
            if (res[adj].size() == 0 || res[adj].back() != root) {
                res[adj].push_back(root);
                dfs(root, adj, adj_set);
            }
        }
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    vector<int> v1{1,2,1,2,1,2}, v2{2,1,1,2,2,1};
}