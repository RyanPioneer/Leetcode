/**
 * Source: https://rb.gy/1iqgf
 * Date: 2023/9/16
 * Skill:
 * Ref: https://rb.gy/izeso
 * Runtime: 76 ms, faster than 77.38% of C++ online submissions
 * Memory Usage: 116.91 MB, less than 34.23% of C++ online submissions
 * Time complexity: O(n*k)
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int rearrangeSticks(int n, int k) {
        int mod = 1e9+7;
        vector<long long> dp(n + 1, 1);
        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] * (i - 1) % mod;
        for (int i = 2; i <= k; i++) {
            vector<long long> dp2 = dp;
            dp[i] = 1;
            for (int j = i + 1; j <= n; j++)
                dp[j] = (dp2[j - 1] + dp[j - 1] * (j - 1)  % mod) % mod;
        }
        return dp[n];
    }
};


int main() {
    Solution s;
    vector<int> nums{1,1,3,3};
    vector<vector<int>> arr{{0,1,0,0,0}, {0,1,0,1,0}, {0,0,0,1,0}};
}