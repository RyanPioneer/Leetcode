/**
 * Source: https://rb.gy/4iwm7
 * Date: 2023/9/17
 * Skill:
 * Runtime: 462 ms, faster than 50.00% of C++ online submissions
 * Memory Usage: 178.2 MB, less than 87.50% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<int> res(n, -1);
        vector<vector<pairs>> adj_list(n);
        for (auto e: edges) {
            adj_list[e[0]].push_back({e[1], 1});
            adj_list[e[1]].push_back({e[0], 0});
        }
        res[0] = dfs1(0, -1, adj_list);
        dfs2(0, -1, adj_list, res);
        return res;
    }
    int dfs1(int cur, int parent, vector<vector<pairs>>& adj_list) {
        int num = 0;
        for (int i = 0; i < adj_list[cur].size(); i++) {
            if (adj_list[cur][i].first == parent)
                continue;
            num += 1 - adj_list[cur][i].second + dfs1(adj_list[cur][i].first, cur, adj_list);
        }
        return num;
    }
    void dfs2(int cur, int parent, vector<vector<pairs>>& adj_list, vector<int>& res) {
        for (int i = 0; i < adj_list[cur].size(); i++) {
            if (adj_list[cur][i].first == parent)
                continue;
            res[adj_list[cur][i].first] = res[cur] + (adj_list[cur][i].second == 1 ? 1 : -1);
            dfs2(adj_list[cur][i].first, cur, adj_list, res);
        }
    }
};

int main() {
    Solution s;
    vector<int> nums{8,7,3,5,7,2,4,9};
    vector<vector<int>> arr{{0,1,0,0,0}, {0,1,0,1,0}, {0,0,0,1,0}};
}