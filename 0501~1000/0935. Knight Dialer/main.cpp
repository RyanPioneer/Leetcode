/**
 * Source: is.gd/0EqaYG
 * Date: 2023/11/24
 * Skill:
 * Ref:
 * Runtime: 7 ms, faster than 93.48% of C++ online submissions
 * Memory Usage: 6.20 MB, less than 100.00% of C++ online submissions
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
    int knightDialer(int n) {
        ll dp[10] = {0}, dp2[10] = {0}, res = 0;
        for (int i = 0; i < 10; i++) dp[i] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 10; j++) {
                dp2[j] = dp[j];
                dp[j] = 0;
            }
            dp[0] = (dp2[4] + dp2[6]) % mod;
            dp[1] = (dp2[6] + dp2[8]) % mod;
            dp[2] = (dp2[7] + dp2[9]) % mod;
            dp[3] = (dp2[4] + dp2[8]) % mod;
            dp[4] = (dp2[0] + dp2[3] + dp2[9]) % mod;
            dp[6] = (dp2[0] + dp2[1] + dp2[7]) % mod;
            dp[7] = (dp2[2] + dp2[6]) % mod;
            dp[8] = (dp2[1] + dp2[3]) % mod;
            dp[9] = (dp2[2] + dp2[4]) % mod;
        }
        for (int i = 0; i < 10; i++) res = (res + dp[i]) % mod;
        return res;
    }
};