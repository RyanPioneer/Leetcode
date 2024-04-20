/**
 * Source: is.gd/Eb8jNA
 * Date: 2024/4/20
 * Skill:
 * Ref:
 * Runtime: 72 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 11.57 MB, less than 100.00% of C++ online submissions
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
const int MX = 18;


class Solution {
public:
    long long minimumTime(vector<int>& power) {
        int n = power.size();
        int finalState = (1 << n) - 1;
        ll dp[1 << MX];
        fill(dp, dp + (1 << MX), LLONG_MAX);
        dp[0] = 0;

        for (int state = 1; state <= finalState; ++state) {
            int bitNUm = __builtin_popcount(state);
            for (int j = 0; j < n; ++j) {
                if (((state >> j) & 1) != 0) {
                    int substate = state - (1 << j);
                    dp[state] = min(dp[state], dp[substate] + (power[j] - 1) / bitNUm + 1);
                }
            }
        }
        return dp[finalState];
    }
};