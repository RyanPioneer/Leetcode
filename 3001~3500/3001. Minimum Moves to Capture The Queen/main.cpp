/**
 * Source: jpeg.ly/P1-5L
 * Date: 2024/1/13
 * Skill:
 * Ref:
 * Runtime: 12 ms, faster than 5.80% of C++ online submissions
 * Memory Usage: 10.30 MB, less than 9.31% of C++ online submissions
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


class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        unordered_set<int> visited;
        int step = 0, dir[5] = {0, 1, 0, -1, 0};
        int diag[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        queue<int> q;
        int cur = a + b * 9 + c * 81 + d * 729;
        visited.insert(cur);
        q.push(cur);
        while (!q.empty()) {
            int sz = SZ(q);
            while (sz--) {
                int state = q.front();
                q.pop();
                int a1 = state % 9, b1 = state / 9 % 9, c1 = state / 81 % 9, d1 = state / 729 % 9;
                if (a1 == e && b1 == f) return step;
                if (c1 == e && d1 == f) return step;
                for (int i = 0; i < 4; i++) {
                    int xx = a1 + dir[i], yy = b1 + dir[i + 1];
                    while (true) {
                        if (!check(xx, yy)) break;
                        if (xx == e && yy == f) return step + 1;
                        if (xx == c1 && yy == d1) break;
                        int next_state = xx + yy * 9 + c1 * 81 + d1 * 729;
                        if (visited.find(next_state) == end(visited)) {
                            visited.insert(next_state);
                            q.push(next_state);
                        }
                        xx += dir[i];
                        yy += dir[i + 1];
                    }
                }
                for (int i = 0; i < 4; i++) {
                    int xx = c1 + diag[i][0], yy = d1 + diag[i][1];
                    while (true) {
                        if (!check(xx, yy)) break;
                        if (xx == e && yy == f) return step + 1;
                        if (xx == a1 && yy == b1) break;
                        int next_state = a1 + b1 * 9 + xx * 81 + yy * 729;
                        if (visited.find(next_state) == end(visited)) {
                            visited.insert(next_state);
                            q.push(next_state);
                        }
                        xx += diag[i][0];
                        yy += diag[i][1];
                    }
                }
            }
            step++;
        }
        return -1;
    }
    bool check(int x, int y) {
        return x > 0 && x < 9 && y > 0 && y < 9;
    }
};