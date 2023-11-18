/**
 * Source: twtr.to/Dg_a0
 * Date: 2023/11/18
 * Skill:
 * Runtime: 123 ms, faster than 40.68% of C++ online submissions
 * Memory Usage: 26.28 MB, less than 85.31% of C++ online submissions
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


const int MX = 301;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size(), res = 0;
        int dp[MX][MX] = {0};
        for (int i = 0; i < m; i++) dp[i + 1][1] = dp[i][1] + mat[i][0];
        for (int i = 0; i < n; i++) dp[1][i + 1] = dp[1][i] + mat[0][i];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] - dp[i][j] + mat[i][j];
            }
        }
        bool find = false;
        for (int len = min(m, n); len >= 1; len--) {
            if (find) break;
            for (int x = 0; x + len <= m; x++) {
                if (find) break;
                for (int y = 0; y + len <= n; y++) {
                    if (dp[x + len][y + len] - dp[x][y + len] - dp[x + len][y] + dp[x][y] <= threshold) {
                        res = len;
                        find = true;
                        break;
                    }
                }
            }
        }
        return res;
    }
};