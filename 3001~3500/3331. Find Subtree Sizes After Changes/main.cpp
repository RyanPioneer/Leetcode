/**
 * Source: t.ly/-Ji8W
 * Date: 2025/1/23
 * Skill:
 * Ref:
 * Runtime: 1813 ms, faster than 13.42% of C++ online submissions
 * Memory Usage: 299.22 MB, less than 32.90% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      1 <= n <= 10 ** 5
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
const int MOD = 1e9+7, MX = 1e5+1; 


class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        unordered_map<int, vector<int>> mp;

        function<void(int)> dfs = [&](int cur) {
            if (!mp[s[cur] - 'a'].empty()) {
                parent[cur] = mp[s[cur] - 'a'].back();
            }
            mp[s[cur] - 'a'].push_back(cur);
            for (auto &i: adj[cur]) {
                dfs(i);
            }
            mp[s[cur] - 'a'].pop_back();
        };

        dfs(0);

        vector<int> res(n, 0);

        vector<vector<int>> adj2(n);
        for (int i = 1; i < n; i++) {
            adj2[parent[i]].push_back(i);
        }

        function<int(int)> dfs2 = [&](int cur) {
            int sz = 1;
            for (auto &i: adj2[cur]) {
                sz += dfs2(i);
            }
            res[cur] = sz;
            return sz;
        };

        dfs2(0);
        return res;
    }
};
