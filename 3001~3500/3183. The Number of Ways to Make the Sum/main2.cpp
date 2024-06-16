/**
 * Source: ibit.ly/15hQN
 * Date: 2024/6/16
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 7.75 MB, less than 45.26% of C++ online submissions
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
const ll MOD = 1e9+7, MX = 1e5+10;
int dp[MX] = {1};


class Solution {
public:
    int numberOfWays(int n) {
        if (!dp[1]) {
            for (auto i: {1,2,6}) {
                for (int j = i; j <= 1e5; j++) {
                    if (j - i >= 0) {
                        dp[j] = (dp[j] + dp[j - i]) % MOD;
                    }
                }
            }
        }
        return (dp[n] + (n >= 4 ? dp[n-4] : 0) + (n >= 8 ? dp[n-8] : 0)) % MOD;
    }
};