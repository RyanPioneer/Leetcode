/**
 * Source: ibit.ly/cWwdV
 * Date: 2025/1/14
 * Skill:
 * Ref:
 * Runtime: 8 ms, faster than 94.88% of C++ online submissions
 * Memory Usage: 138.97 MB, less than 95.22% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      4 <= b.length <= 10 ** 5
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


class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        vector<ll> dp(4, LLONG_MIN/4);
        for (int i = 0; i < n; ++i) {
            dp[3] = max(dp[3], dp[2] + (ll)a[3] * b[i]);
            dp[2] = max(dp[2], dp[1] + (ll)a[2] * b[i]);
            dp[1] = max(dp[1], dp[0] + (ll)a[1] * b[i]);
            dp[0] = max(dp[0], (ll)a[0] * b[i]);
        }
        return dp[3];
    }
};
