/**
 * Source: twtr.to/ofh9T
 * Date: 2023/10/16
 * Skill:
 * Runtime: 538 ms, faster than 72.48% of C++ online submissions
 * Memory Usage: 171.84 MB, less than 57.05% of C++ online submissions
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
#include <bitset>
#include <functional>

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = parent.size();
        ll res = 0;
        unordered_map<int, ll> node2cnt;
        vector<vector<pair<int, char>>> adj_list(n);
        for (int i = 1; i < n; ++i)
            adj_list[parent[i]].push_back({i, s[i]});

        function<void(int, int)> dfs;
        dfs = [&](int node, int path) {
            if (node2cnt.find(path) != node2cnt.end())
                res += node2cnt[path];
            for (int i = 0; i < 26; i++) {
                int nxt = path ^ (1 << i);
                if (node2cnt.find(nxt) != node2cnt.end())
                    res += node2cnt[nxt];
            }
            node2cnt[path] += 1;
            for (auto [child, ch]: adj_list[node]) {
                int nxt = path ^ (1 << (ch - 'a'));
                dfs(child, nxt);
            }
        };
        dfs(0, 0);
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}