/**
 * Source: twtr.to/n_gcq
 * Date: 2023/11/18
 * Skill:
 * Runtime: 29 ms, faster than 91.03% of C++ online submissions
 * Memory Usage: 24.68 MB, less than 92.41% of C++ online submissions
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
#include <list>


using namespace std;


class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int res = 0, n = arr1.size();
        for (int i = 0; i < (1 << 3); i++) {
            int mx = INT32_MIN, mi = INT32_MAX;
            for (int j = 0; j < n; j++) {
                int num = 0;
                num += (((i >> 0) & 1) != 0 ? j : -j);
                num += (((i >> 1) & 1) != 0 ? arr1[j] : -arr1[j]);
                num += (((i >> 2) & 1) != 0 ? arr2[j] : -arr2[j]);
                mi = min(mi, num);
                mx = max(mx, num);
            }
            res = max(res, mx - mi);
        }
        return res;
    }
};