/**
 * Source: ibit.ly/UFi6o
 * Date: 2024/6/9
 * Skill:
 * Ref:
 * Runtime: 214 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 8.26 MB, less than 100.00% of C++ online submissions
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
const int MX = 1e3+10, MOD = 1e9+7;


class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        ll dp[MX];
        fill(dp, dp + n, 1ll);
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] = (dp[j-1] + dp[j]) % MOD;
            }
        }
        return dp[n-1];
    }
};