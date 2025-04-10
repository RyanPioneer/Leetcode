/**
 * Source: t.ly/JKGDN
 * Date: 2025/3/9
 * Skill:
 * Ref:
 * Runtime: 45 ms, faster than 50.00% of C++ online submissions
 * Memory Usage: 145.86 MB, less than 65.31% of C++ online submissions
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
const int MX = 1e5 + 5;

class Solution {
public:
    int longestCommonPrefix(string s, string t)
    {
        int dp[MX][2] = {0}, res = 0;
        int n = s.size(), m = t.size();
        dp[0][0] = s[0] == t[0] ? 1 : INT32_MIN / 2;
        dp[0][1] = 0;
        res = (dp[0][0] == 1) ? 1 : 0;
        for (int i = 1; i < min(n, m+1); i++) {
            if (i < m && dp[i - 1][0] >= 0) {
                dp[i][0] = dp[i - 1][0] + (s[i] == t[i] ? 1 : INT32_MIN / 4);
                res = max(res, dp[i][0]);
            } else {
                dp[i][0] = INT32_MIN / 2;
            }
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + (s[i] == t[i-1] ? 1 : INT32_MIN / 2));
            res = max(res, dp[i][1]);
        }
        return res;
    }
};
eey
aaye