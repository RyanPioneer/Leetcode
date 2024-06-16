/**
 * Source: t.ly/28-G3
 * Date: 2024/6/5
 * Skill:
 * Ref:
 * Runtime: 71 ms, faster than 36.63% of C++ online submissions
 * Memory Usage: 42.97 MB, less than 27.33% of C++ online submissions
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


class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), res = 0;
        int dir[4][2] = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(4, 0)));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!mat[i][j]) continue;
                for (int k = 0; k < 4; k++) {
                    int xx = i + dir[k][0], yy = j + dir[k][1];
                    int dis;
                    if (xx < 0 || xx >= n || yy < 0 || yy >= m) dis = 0;
                    else dis = dp[xx][yy][k];
                    dp[i][j][k] = 1 + dis;
                    res = max(res, dp[i][j][k]);
                }
            }
        }
        return res;
    }
};