/**
 * Source: t.ly/Jgmol
 * Date: 2024/5/6
 * Skill:
 * Ref:
 * Runtime: 11 ms, faster than 70.81% of C++ online submissions
 * Memory Usage: 11.83 MB, less than 90.11% of C++ online submissions
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

#define ll long long
const int MX = 1e3+2;


class Solution {
public:
    bool isValidPalindrome(string s, int K) {
        int dp[MX][MX] = {0}, len = s.length();
        for (int i = 0; i + 1 < len; i++) {
            if (s[i] != s[i + 1]) {
                dp[i][i + 1] = 1;
            }
        }
        for (int i = 3; i <= len; i++) {
            for (int j = 0; j + i <= len; j++) {
                int k = j + i - 1;
                if (s[j] == s[k]) {
                    dp[j][k] = dp[j + 1][k - 1];
                } else {
                    dp[j][k] = min({dp[j + 1][k - 1] + 2, dp[j + 1][k] + 1, dp[j][k - 1] + 1});
                }
            }
        }
        return dp[0][len - 1] <= K;
    }
};