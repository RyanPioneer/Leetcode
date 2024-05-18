/**
 * Source: ibit.ly/WboKQ
 * Date: 2024/5/18
 * Skill:
 * Ref:
 * Runtime: 11 ms, faster than 53.97% of C++ online submissions
 * Memory Usage: 7.94 MB, less than 85.71% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
#define For(i, a, b) for (int i = (a); i <= (b); i++)
#define Rep(i, a, b) for (int i = (a); i >= (b); i--)


const int MX = 1e5+10, MOD = 1e9+7;


class Solution {
public:
    int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup) {
        ll dp[MX] = {1};
        ll res = 0;
        For(i,1,maxLength) {
            dp[i] = 0;
            if (i >= oneGroup) {
                dp[i] = (dp[i] + dp[i - oneGroup]) % MOD;
            }
            if (i >= zeroGroup) {
                dp[i] = (dp[i] + dp[i - zeroGroup]) % MOD;
            }
            if (i >= minLength) res = (res + dp[i]) % MOD;
        }
        return res;
    }
};