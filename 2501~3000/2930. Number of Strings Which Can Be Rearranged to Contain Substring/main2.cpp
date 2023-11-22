/**
 * Source: t.ly/SG59J
 * Date: 2023/11/22
 * Skill:
 * Ref:
 * Runtime: 228 ms, faster than 53.63% of C++ online submissions
 * Memory Usage: 6.26 MB, less than 95.09% of C++ online submissions
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
ll mod = 1e9+7;


class Solution {
public:
    int stringCount(int n) {
        ll dp[2][3][2] = {0}, dp2[2][3][2] = {0};
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 12; j++) {
                dp2[j / 6][j / 2 % 3][j % 2] = dp[j / 6][j / 2 % 3][j % 2];
                dp[j / 6][j / 2 % 3][j % 2] = 0;
            }
            for (int j = 0; j < 26; j++) {
                for (int l = 0; l < 2; l++) {
                    for (int e = 0; e < 3; e++) {
                        for (int t = 0; t < 2; t++) {
                            if (j == 'l' - 'a' && l == 1) {
                                dp[l][e][t] += dp2[l - 1][e][t];
                            } else if (j == 'e' - 'a' && e == 1) {
                                dp[l][e][t] += dp2[l][e - 1][t];
                            } else if (j == 'e' - 'a' && e == 2) {
                                dp[l][e][t] += dp2[l][e - 1][t];
                            } else if (j == 't' - 'a' && t == 1) {
                                dp[l][e][t] += dp2[l][e][t - 1];
                            } else {
                                dp[l][e][t] = (dp[l][e][t] + dp2[l][e][t]) % mod;
                            }
                        }
                    }
                }
            }
        }
        return dp[1][2][1] % mod;
    }
};