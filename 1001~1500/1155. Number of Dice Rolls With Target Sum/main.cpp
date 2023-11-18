/**
 * Source: twtr.to/ar3n9
 * Date: 2023/11/18
 * Skill:
 * Runtime: 12 ms, faster than 90.20% of C++ online submissions
 * Memory Usage: 6.25 MB, less than 100.00% of C++ online submissions
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
    int numRollsToTarget(int n, int k, int target) {
        ll mod = 1e9+7, dp[MX] = {1}, dp2[MX] = {0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= target; j++) {
                dp2[j] = dp[j];
                dp[j] = 0;
            }
            for (int cur_num = 1; cur_num <= k; cur_num++) {
                for (int total = cur_num; total <= target; total++) {
                    dp[total] = (dp[total] + dp2[total - cur_num]) % mod;
                }
            }
        }
        return dp[target] % mod;
    }
};