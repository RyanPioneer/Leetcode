/**
 * Source: jpeg.ly/G7nUX
 * Date: 2023/12/16
 * Skill:
 * Ref:
 * Runtime: 13 ms, faster than 43.96% of C++ online submissions
 * Memory Usage: 12.50 MB, less than 92.95% of C++ online submissions
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
    int m, n;
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        m = rows, n = cols;
        int num = rows * cols - 1, len = 1, dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        vector<vector<int>> res;
        res.push_back({rStart, cStart});
        while (num) {
            for (int i = 0; i < 4; i++) {
                int step;
                if (i == 0) step = len - 1;
                else if (i == 1 || i == 2) step = len;
                else step = len + 1;
                while (step--) {
                    rStart += dir[i][0];
                    cStart += dir[i][1];
                    if (check(rStart, cStart)) {
                        res.push_back({rStart, cStart});
                        num--;
                        if (num == 0) return res;
                    }
                }
            }
            len += 2;
        }
        return res;
    }
    bool check(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};