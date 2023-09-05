/**
 * Source: https://rb.gy/3vgd4
 * Date: 2023/9/5
 * Skill:
 * Runtime: 691 ms, faster than 84.32% of C++ online submissions
 * Memory Usage: 218.51 MB, less than 81.28% of C++ online submissions
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
#include <stack>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;


class Solution {
public:
    int level[10002];
    int count[10002][27];
    int parent[10002];
    int ancestor[10002][14];
    int limit;
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<pairs>> adj_set(n);
        for (auto edge: edges) {
            adj_set[edge[0]].push_back({edge[1], edge[2]});
            adj_set[edge[1]].push_back({edge[0], edge[2]});
        }
        dfs(0, -1, 0, adj_set);
        vector<int> res;
        limit = floor(log(n) / log(2));
        ancestor[0][0] = 0;
        for (int i = 1; i < n; i++)
            ancestor[i][0] = parent[i];
        for (int i = 1; i <= limit; i++)
            for (int j = 0; j < n; j++)
                ancestor[j][i] = ancestor[ancestor[j][i - 1]][i - 1];
        for (auto q: queries) {
            int lca = get_lca(q[0], q[1]), total = 0, max_val = 0;
            for (int i = 0; i < 27; i++) {
                int n = count[q[0]][i] + count[q[1]][i] - 2 * count[lca][i];
                total += n;
                max_val = max(max_val, n);
            }
            res.push_back(total - max_val);
        }
        return res;
    }
    void dfs(int cur, int p, int l, vector<vector<pairs>>& adj_set) {
        level[cur] = l;
        for (auto adj: adj_set[cur]) {
            if (adj.first == p) continue;
            int num = adj.second;
            for (int i = 0; i < 27; i++)
                count[adj.first][i] = count[cur][i];
            count[adj.first][num]++;
            parent[adj.first] = cur;
            dfs(adj.first, cur, l + 1, adj_set);
        }
    }
    int get_k_ancestor(int a, int k) {
        for (int i = 0; i <= limit; i++)
            if ((k >> i) & 1 != 0)
                a = ancestor[a][i];
        return a;
    }
    int get_lca(int a, int b) {
        if (level[a] < level[b])
            b = get_k_ancestor(b, level[b] - level[a]);
        else
            a = get_k_ancestor(a, level[a] - level[b]);
        int left = 0, right = level[a];
        while (left < right) {
            int mid = (left + right) / 2;
            int aa = get_k_ancestor(a, mid), bb = get_k_ancestor(b, mid);
            if (aa == bb)
                right = mid;
            else
                left = mid + 1;
        }
        return get_k_ancestor(a, left);
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
    cout << (4 & 1);
}