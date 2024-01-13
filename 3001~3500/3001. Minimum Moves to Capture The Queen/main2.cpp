/**
 * Source: jpeg.ly/P1-5L
 * Date: 2024/1/13
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.53 MB, less than 9.31% of C++ online submissions
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
        int dir[5] = {0, 1, 0, -1, 0};
        int diag[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        for (int i = 0; i < 4; i++) {
            int x = a, y = b;
            while (true) {
                x += dir[i], y += dir[i + 1];
                if (x <= 0 || x > 8 || y <= 0 || y > 8) break;
                if (x == c && y == d) break;
                if (x == e && y == f) return 1;
            }
        }
        for (int i = 0; i < 4; i++) {
            int x = c, y = d;
            while (true) {
                x += diag[i][0], y += diag[i][1];
                if (x <= 0 || x > 8 || y <= 0 || y > 8) break;
                if (x == a && y == b) break;
                if (x == e && y == f) return 1;
            }
        }
        return 2;
    }
};