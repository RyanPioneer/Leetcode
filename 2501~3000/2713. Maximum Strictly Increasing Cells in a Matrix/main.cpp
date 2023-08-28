/**
 * Source: https://rb.gy/vlzz8
 * Date: 2023/8/28
 * Skill:
 * Runtime: TLE
 * Memory Usage:
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;


class Solution {
public:
    int maxIncreasingCells(vector<vector<int> >& mat) {
        int m = mat.size(), n = mat[0].size(), res = 0;
        vector<vector<int> > dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, helper(mat, dp, i, j));
            }
        }
        return res;
    }
    int helper(vector<vector<int> >& mat, vector<vector<int> >& dp, int x, int y) {
        if (dp[x][y] != 0)
            return dp[x][y];
        int m = mat.size(), n = mat[0].size();
        int res = 0;
        for (int i = 0; i <m; i++) {
            if (mat[i][y] > mat[x][y]) {
                res = max(res, helper(mat, dp, i, y));
            }
        }
        for (int i = 0; i <n; i++) {
            if (mat[x][i] > mat[x][y]) {
                res = max(res, helper(mat, dp, x, i));
            }
        }
        dp[x][y] = res + 1;
        return dp[x][y];
    }
};

int main() {
    Solution s;
    cout << "test";
}

//static const auto io_sync_off = []() {
//    // turn off sync
//    std::ios::sync_with_stdio(false);
//    // untie in/out streams
//    std::cin.tie(nullptr);
//    return nullptr;
//}();