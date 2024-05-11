/**
 * Source: t.ly/CIQF1
 * Date: 2024/5/11
 * Skill:
 * Ref:
 * Runtime: 13 ms, faster than 73.76% of C++ online submissions
 * Memory Usage: 16.10 MB, less than 70.81% of C++ online submissions
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
    int countComponents(int n, vector<vector<int>>& edges) {
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
        for (int i = 0; i < n; i++) {
            Set.insert(findGroup(i));
        }
        return Set.size();
    }
};