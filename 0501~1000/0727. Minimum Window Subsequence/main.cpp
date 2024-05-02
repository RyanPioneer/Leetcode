/**
 * Source: t.ly/HqAFE
 * Date: 2024/5/1
 * Skill:
 * Ref:
 * Runtime: 65 ms, faster than 55.12% of C++ online submissions
 * Memory Usage: 18.54 MB, less than 40.99% of C++ online submissions
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

const int MX = 2e4+2;


class Solution {
public:
    string minWindow(string s1, string s2) {
        string res;
        int dp[MX][102], len1 = s1.length(), len2 = s2.length();

        fill(dp[0], dp[MX - 1] + 102, -1);
        for (int i = 1; i <= len1; i++) {
            if (s1[i - 1] == s2[0]) dp[i][1] = 1;
            else if (dp[i - 1][1] != -1) dp[i][1] = dp[i - 1][1] + 1;
            for (int j = 2; j <= min(i, len2); j++) {
                if (dp[i - 1][j] != -1) dp[i][j] = dp[i - 1][j] + 1;
                if (s1[i - 1] == s2[j - 1] && dp[i - 1][j - 1] != -1) {
                    if (dp[i][j] == -1) dp[i][j] = dp[i - 1][j - 1] + 1;
                    else dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }

        for (int i = len2; i <= len1; i++) {
            if (dp[i][len2] != -1 && (res.empty() || dp[i][len2] < res.length())) {
                res = s1.substr(i - dp[i][len2], dp[i][len2]);
            }
        }
        return res;
    }
};