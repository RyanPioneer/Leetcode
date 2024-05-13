/**
 * Source: ibit.ly/qirBz
 * Date: 2024/5/13
 * Skill:
 * Ref:
 * Runtime: 21 ms, faster than 77.55% of C++ online submissions
 * Memory Usage: 16.92 MB, less than 73.49% of C++ online submissions
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
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(), n = rooms[0].size();
        int dir[5] = {0, 1, 0, -1, 0};
        queue<PII> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    q.push(MK(i, j));
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int xx = x + dir[i], yy = y + dir[i + 1];
                if (xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
                if (rooms[xx][yy] != -1 && rooms[xx][yy] > rooms[x][y] + 1) {
                    rooms[xx][yy] = rooms[x][y] + 1;
                    q.push(MK(xx, yy));
                }
            }
        }
    }
};