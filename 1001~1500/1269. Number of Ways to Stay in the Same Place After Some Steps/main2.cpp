/**
 * Source: ibit.ly/W5FvC
 * Date: 2023/10/15
 * Skill:
 * Runtime: 4 ms, faster than 97.62% of C++ online submissions
 * Memory Usage: 6.39 MB, less than 95.45% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= steps <= 500
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int numWays(int steps, int arrLen) {
        if (arrLen == 1)
            return 1;
        arrLen = min(steps, arrLen);
        ll res = 0, mod = 1e9+7;
        ll dp[501] = {0};
        dp[0] = 1;
        for (int i = 0; i < steps; i++) {
            ll dp2[501];
            for (int j = 0; j < arrLen; j++)
                dp2[j] = dp[j];
            dp[0] = dp2[0] + dp2[1];
            dp[arrLen - 1] = dp2[arrLen - 1] + dp2[arrLen - 2];
            for (int idx = 1; idx < arrLen - 1; idx++)
                dp[idx] = dp2[idx - 1] % mod + dp2[idx] % mod + dp2[idx + 1] % mod;
        }
        return dp[0] % mod;
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
    int c = test(2, 2);
    cout << c << endl;
}