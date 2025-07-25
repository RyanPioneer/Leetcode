/**
 * Source: t.ly/1kDLs
 * Date: 2025/7/25
 * Skill:
 * Ref:
 * Runtime: 108 ms, faster than 71.95% of C++ online submissions
 * Memory Usage: 213.06 MB, less than 100.00% of C++ online submissions
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
    vector<int> par;
    int minTime(int n, vector<vector<int>>& edges, int k) {
        par.resize(n);
        int lo = 0, hi = 1e9 + 1;
        while (lo < hi) {
            ll mid = (lo + hi) / 2;
            if (helper(n, edges, k, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }

    int findParent(int num) {
        if (par[num] != num) {
            par[num] = findParent(par[num]);
        }
        return par[num];
    };

    int unionSets(int a, int b) {
        int rootA = findParent(a);
        int rootB = findParent(b);
        if (rootA != rootB) {
            par[rootA] = rootB;
            return 1;
        }
        return 0;
    };

   private:
    bool helper(int n, vector<vector<int>>& edges, int k, ll time) {
        iota(par.begin(), par.end(), 0);
        int cnt = n;
        for (const auto& edge : edges) {
            if (edge[2] > time) {
                cnt -= unionSets(edge[0], edge[1]);
            }
        }
        return cnt >= k;
    }
};