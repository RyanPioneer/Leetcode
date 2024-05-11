/**
 * Source: t.ly/PFda-
 * Date: 2024/5/11
 * Skill:
 * Ref:
 * Runtime: 14 ms, faster than 54.78% of C++ online submissions
 * Memory Usage: 16.04 MB, less than 47.85% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */


#include <iostream>
#include <cstdlib>
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

const int MX = 2e3+2;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        int groups[MX];
        iota(groups, groups + MX, 0);

        function<int(int)> findGroup = [&](int idx) {
            if (groups[idx] != idx) {
                groups[idx] = findGroup(groups[idx]);
            }
            return groups[idx];
        };

        function<void(int, int)> unionGroup = [&](int idx1, int idx2) {
            int g1 = findGroup(idx1), g2 = findGroup(idx2);
            if (g1 != g2) {
                groups[max(g1, g2)] = min(g1, g2);
            }
        };

        for (auto &e: edges) {
            unionGroup(e[0], e[1]);
        }

        unordered_set<int> Set;
        for (int i = 0; i + 1 < n; i++) {
            if (findGroup(i) != findGroup(i + 1)) {
                return false;
            }
        }
        return true;
    }
};