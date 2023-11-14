/**
 * Source: t.ly/zwOz4
 * Date: 2023/11/14
 * Skill:
 * Runtime: 126 ms, faster than 43.62% of C++ online submissions
 * Memory Usage: 15.47 MB, less than 79.79% of C++ online submissions
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


#define ll long long

const int MX = 1001;


class Solution {
public:
    int countPalindromicSubsequences(string s) {
        ll mod = 1e9+7, dp[MX][MX] = {0};
        int len = s.length(), next[MX][4], prev[MX][4];
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < 4; j++) {
                next[i][j] = len;
                prev[i][j] = -1;
            }
            dp[i][i] = 1;
        }
        for (int i = 0; i < 4; i++) {
            int cur = 0;
            for (int j = 0; j < len; j++) {
                if (s[j] != 'a' + i) continue;
                while (cur <= j) {
                    next[cur++][i] = j;
                }
            }
            cur = len - 1;
            for (int j = len - 1; j >= 0; j--) {
                if (s[j] != 'a' + i) continue;
                while (cur >= j) {
                    prev[cur--][i] = j;
                }
            }
        }
        for (int l = 2; l <= len; l++) {
            for (int i = 0; i + l <= len; i++) {
                int j = i + l - 1;
                for (int k = 0; k < 4; k++) {
                    if (next[i][k] < prev[j][k]) {
                        dp[i][j] += dp[next[i][k] + 1][prev[j][k] - 1] + 1;
                    }
                    if (next[i][k] <= j) {
                        dp[i][j]++;
                    }
                    dp[i][j] %= mod;
                }
            }
        }
        return dp[0][len - 1];
    }
};


int main() {
    Solution s;
}