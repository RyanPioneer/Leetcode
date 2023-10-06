/**
 * Source: ibit.ly/QHdRo
 * Date: 2023/10/6
 * Skill:
 * Runtime: 2 ms, faster than 49.96% of C++ online submissions
 * Memory Usage: 6.44 MB, less than 29.03% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3)
            return n - 1;
        int dp[59];
        for (int i = 0; i < 59; i++)
            dp[i] = 1;
        for (int i = 4; i <= n; i++)
            for (int j = 1; j <= i / 2; j++)
                dp[i] = max(dp[i], max(j, dp[j]) * max(i - j, dp[i - j]));
        return dp[n];
    }
};



int main() {
    Solution s;
    vector<int> nums{2, 3, 3, 2};
}