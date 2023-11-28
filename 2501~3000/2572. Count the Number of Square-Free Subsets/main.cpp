/**
 * Source: is.gd/QuMWGx
 * Date: 2023/11/28
 * Skill:
 * Ref:
 * Runtime: 20 ms, faster than 88.62% of C++ online submissions
 * Memory Usage: 8.63 MB, less than 94.31% of C++ online submissions
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
const int MX = 1024;


class Solution {
public:
    int squareFreeSubsets(vector<int>& nums) {
        int one_num = 0;
        vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        ll dp[MX] = {0}, dp2[MX] = {0}, res = 0;
        dp[0] = 1;
        for (auto &n: nums) {
            if (n == 1) {
                one_num++;
                continue;
            }
            int mask = 0;
            bool feasible = true;
            for (int i = 0; i < 10; i++) {
                int k = primes[i] * primes[i];
                if (n % k == 0) {
                    feasible = false;
                    break;
                }
                if (n % primes[i] == 0) mask |= (1 << i);
            }
            if (!feasible) continue;
            for (int i = 0; i < MX; i++) {
                dp2[i] = dp[i] + dp2[i];
                dp[i] = 0;
            }
            for (int i = 0; i < MX; i++) {
                if ((mask & i) == 0) {
                    dp[mask | i] += dp2[i];
                }
            }
        }
        ll one = 1;
        for (int i = 0; i < one_num; i++) one = one * 2 % mod;
        for (int i = 1; i < MX; i++) res = (res + dp[i] + dp2[i]) % mod;
        return res == 0 ? one - 1 : ((res + 1) * one - 1) % mod;
    }
};