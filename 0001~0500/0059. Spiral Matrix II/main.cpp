/**
 * Source: jpeg.ly/35Vwu
 * Date: 2023/12/16
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.90 MB, less than 88.81% of C++ online submissions
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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int x = 0, y = -1, cur = 1, dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int len = n; len > 0; len -= 2) {
            for (int i = 0; i < 4; i++) {
                int step = i == 0 ? len : len - 1;
                if (i == 3) step--;
                while (step-- > 0) {
                    x += dir[i][0];
                    y += dir[i][1];
                    res[x][y] = cur++;
                }
            }
        }
        return res;
    }
};