/**
 * Source: is.gd/u2mv4I
 * Date: 2023/12/1
 * Skill:
 * Ref:
 * Runtime: 489 ms, faster than 91.25% of C++ online submissions
 * Memory Usage: 113.72 MB, less than 88.05% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
#define ll long long
#define MP(X, Y) make_pair(X, Y)
#define x first
#define y second
typedef pair<int, int> PII;
typedef pair<char, char> PCC;
ll mod = 1e9+7;
const int MX = 50;


class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        PII pos = {0, 0};
        int res = 0, m = SZ(forest), n = SZ(forest[0]), dir[5] = {0, 1, 0, -1, 0};
        int visited[MX][MX];
        vector<int> heights;
        for (auto &i: forest) {
            for (auto &j: i) {
                if (j > 1) heights.push_back(j);
            }
        }
        sort(begin(heights), end(heights));
        if (forest[0][0] == 0) return -1;
        for (auto &h: heights) {
            if (forest[pos.x][pos.y] == h) continue;
            queue<PII> q;
            fill(visited[0], visited[MX - 1] + MX, 0);
            visited[pos.first][pos.second] = 1;
            q.push(pos);
            int step = 0;
            bool found = false;
            while (!q.empty()) {
                if (found) break;
                int sz = SZ(q);
                step++;
                while (sz--) {
                    if (found) break;
                    PII cur = q.front();
                    q.pop();
                    for (int i = 0; i < 4; i++) {
                        int x = cur.first + dir[i], y = cur.second + dir[i + 1];
                        if (x < 0 || x >= m || y < 0 || y >= n) continue;
                        if (visited[x][y] == 1 || forest[x][y] == 0) continue;
                        if (forest[x][y] == h) {
                            res += step;
                            found = true;
                            pos = {x, y};
                            break;
                        }
                        visited[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }
            if (!found) return -1;
        }
        return res;
    }
};