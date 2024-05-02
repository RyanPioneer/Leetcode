/**
 * Source: t.ly/9CSjZ
 * Date: 2024/4/30
 * Skill:
 * Ref:
 * Runtime: 53 ms, faster than 71.58% of C++ online submissions
 * Memory Usage: 21.02 MB, less than 85.53% of C++ online submissions
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
typedef pair<int, int> PII;
#define MK make_pair


class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), dis = -1;
        int dir[5] = {0, 1, 0, -1, 0};
        PII pos;
        for (int i = 0; i < m; i++) {
            bool check = false;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '*') {
                    pos = MK(i, j);
                    check = true;
                    break;
                }
            }
            if (check) break;
        }

        queue<PII> q;
        q.push(pos);

        while (!q.empty()) {
            int sz = q.size();
            dis++;
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();
                for (int j = 0; j < 4; j++) {
                    int xx = x + dir[j], yy = y + dir[j + 1];
                    if (xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
                    if (grid[xx][yy] == '#') return dis + 1;
                    if (grid[xx][yy] == 'O') {
                        grid[xx][yy] = 'X';
                        q.push(MK(xx, yy));
                    }
                }
            }
        }
        return -1;
    }
};