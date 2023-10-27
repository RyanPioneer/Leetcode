/**
 * Source: tinyurl.com/yllc3ktn
 * Date: 2023/10/26
 * Skill:
 * Runtime: 168 ms, faster than 90.78% of C++ online submissions
 * Memory Usage: 13.50 MB, less than 95.46% of C++ online submissions
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
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        const int MX = 871;
        int dp[MX] = {0}, dp2[MX] = {0};
        dp[0] = 1;
        int m = mat.size(), n = mat[0].size(), mi = 0;
        for (auto &i: mat) mi += *min_element(begin(i), end(i));
        int res = abs(mi - target);
        if (mi >= target) return res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < MX; j++) {
                dp2[j] = dp[j];
                dp[j] = 0;
            }
            for (auto &j: mat[i]) {
                for (int k = 0; k + j < MX; k++) {
                    if (dp2[k] == 1) {
                        dp[k + j] = 1;
                        if (i == m - 1) res = min(res, abs(k + j - target));
                    }
                }
            }
        }
        return res;
    }
};


int main() {
//    Solution s;
}