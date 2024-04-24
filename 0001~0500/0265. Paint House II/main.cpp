/**
 * Source: t.ly/iQLsW
 * Date: 2024/4/23
 * Skill:
 * Ref:
 * Runtime: 11 ms, faster than 77.15% of C++ online submissions
 * Memory Usage: 13.74 MB, less than 67.22% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
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

const int MX = 101;

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), k = costs[0].size();
        int mi = INT32_MAX, mi2 = INT32_MAX, idx = -1;

        for (int i = 0; i < k; i++) {
            if (costs[0][i] < mi) {
                mi2 = mi;
                mi = costs[0][i];
                idx = i;
            } else if (costs[0][i] < mi2) {
                mi2 = costs[0][i];
            }
        }

        for (int i = 1; i < n; i++) {
            int mii = INT32_MAX, mii2 = INT32_MAX, id;
            for (int j = 0; j < k; j++) {
                if (j == idx) costs[i][j] += mi2;
                else costs[i][j] += mi;
                if (costs[i][j] < mii) {
                    mii2 = mii;
                    mii = costs[i][j];
                    id = j;
                } else if (costs[i][j] < mii2) {
                    mii2 = costs[i][j];
                }
            }
            mi = mii;
            mi2 = mii2;
            idx = id;
        }

        return *min_element(begin(costs[n - 1]), end(costs[n - 1]));
    }
};