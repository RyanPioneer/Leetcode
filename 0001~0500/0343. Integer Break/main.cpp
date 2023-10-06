/**
 * Source: ibit.ly/QHdRo
 * Date: 2023/10/6
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.31 MB, less than 36.38% of C++ online submissions
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
    int dp[59] = {0};
public:
    int integerBreak(int n) {
        if (n <= 2)
            return 1;
        if (dp[n] != 0)
            return dp[n];
        int res = 0;
        for (int i = 1; i <= n / 2; i++)
            res = max(res, max(i, integerBreak(i))  * max((n - i), integerBreak(n - i)));
        dp[n] = res;
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{2, 3, 3, 2};
}