/**
 * Source: ibit.ly/6SW89
 * Date: 2024/6/24
 * Skill:
 * Ref:
 * Runtime: 282 ms, faster than 14.29% of C++ online submissions
 * Memory Usage: 132.24 MB, less than 28.57% of C++ online submissions
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
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int left = n, right = -1, up = m, down = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    left = min(left, j);
                    right = max(right, j);
                    up = min(up, i);
                    down = max(down, i);
                }
            }
        }
        return (down - up + 1) * (right - left + 1);
    }
};