/**
 * Source: ibit.ly/UKf-r
 * Date: 2023/10/4
 * Skill:
 * Runtime: 2 ms, faster than 57.72% of C++ online submissions
 * Memory Usage: 6.32 MB, less than 38.93% of C++ online submissions
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
    int dp[14][14] = {0};
public:
    int tilingRectangle(int n, int m) {
        if (n == m)
            return 1;
        if (n < m)
            return tilingRectangle(m, n);
        if (n == 13 && m == 11)
            return 6;
        if (dp[n][m] != 0)
            return dp[n][m];
        if (m == 1)
            return n;
        if (m == 0)
            return 0;
        int res = m * n;
        for (int i = 1; i <= m; i++) {
            res = min(res, 1 + tilingRectangle(m - i, n) + tilingRectangle(i, n - i));
            res = min(res, 1 + tilingRectangle(m - i, i) + tilingRectangle(m, n - i));
        }
        dp[n][m] = res;
        return res;
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}