/**
 * Source: is.gd/1Nz6sH
 * Date: 2024/5/20
 * Skill:
 * Ref:
 * Runtime: 30 ms, faster than 62.29% of C++ online submissions
 * Memory Usage: 22.51 MB, less than 40.50% of C++ online submissions
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
#define MK make_pair
typedef pair<int, int> pii;


class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        int dir[5] = {0, 1, 0, -1, 0};
        vector<vector<int>> dr(m, vector<int>(n, 0));
        vector<vector<int>> ul(m, vector<int>(n, 0));

        queue<pii> q1, q2;
        for (int i = 0; i < n; i++) {
            dr[m-1][i] = 1;
            q1.push(MK(m-1, i));
            ul[0][i] = 1;
            q2.push(MK(0, i));
        }
        for (int i = 0; i < m; i++) {
            dr[i][n-1] = 1;
            q1.push(MK(i, n-1));
            ul[i][0] = 1;
            q2.push(MK(i, 0));
        }

        while (!q1.empty()) {
            auto [x, y] = q1.front();
            q1.pop();
            for (int i = 0; i < 4; i++) {
                int xx = x + dir[i], yy = y + dir[i+1];
                if (xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
                if (heights[x][y] > heights[xx][yy]) continue;
                if (!dr[xx][yy]) {
                    dr[xx][yy] = 1;
                    q1.push(MK(xx, yy));
                }
            }
        }

        while (!q2.empty()) {
            auto [x, y] = q2.front();
            q2.pop();
            for (int i = 0; i < 4; i++) {
                int xx = x + dir[i], yy = y + dir[i+1];
                if (xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
                if (heights[x][y] > heights[xx][yy]) continue;
                if (!ul[xx][yy]) {
                    ul[xx][yy] = 1;
                    q2.push(MK(xx, yy));
                }
            }
        }

        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dr[i][j] + ul[i][j] == 2) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};