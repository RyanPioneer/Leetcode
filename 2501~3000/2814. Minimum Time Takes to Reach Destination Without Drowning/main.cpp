/**
 * Source: t.ly/IEFed
 * Date: 2024/5/11
 * Skill:
 * Ref:
 * Runtime: 246 ms, faster than 76.92% of C++ online submissions
 * Memory Usage: 163.20 MB, less than 76.92% of C++ online submissions
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
const int MX = 1e2+2;



class Solution {
public:
    int minimumSeconds(vector<vector<string>>& land) {
        int m = land.size(), n = land[0].size(), dir[5] = {0, 1, 0, -1, 0};
        int time[MX][MX];
        fill(time[0], time[MX - 1] + MX, INT32_MAX);
        PII start;
        queue<PII> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == "S") {
                    land[i][j] = "X";
                    start = MK(i, j);
                }
                if (land[i][j] == "*") {
                    auto k = MK(i, j);
                    q.push(k);
                    time[i][j] = 0;
                    land[i][j] = "X";
                }
            }
        }
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int xx = i + dir[k], yy = j + dir[k + 1];
                if (xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
                if (land[xx][yy] == "X" || land[xx][yy] == "D") continue;
                if (time[xx][yy] != INT32_MAX) continue;
                time[xx][yy] = time[i][j] + 1;
                q.push(MK(xx, yy));
            }
        }

        q.push(start);
        int res = 0;
        bool found = false;
        while (!q.empty() && !found) {
            int sz = q.size();
            res++;
            while (sz--) {
                auto [i, j] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int xx = i + dir[k], yy = j + dir[k + 1];
                    if (xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
                    if (land[xx][yy] == "X") continue;
                    if (land[xx][yy] == "D") {
                        return res;
                    }
                    if (time[xx][yy] <= res) continue;
                    land[xx][yy] = "X";
                    q.push(MK(xx, yy));
                }
            }
        }
        return -1;
    }
};