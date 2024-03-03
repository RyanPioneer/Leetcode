/**
 * Source: is.gd/abTMKS
 * Date: 2024/3/3
 * Skill:
 * Ref:
 * Runtime: 43 ms, faster than 80.00% of C++ online submissions
 * Memory Usage: 41.08 MB, less than 60.00% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      3 <= n <= 49
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
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size(), nums[2][3] = {0}, res = INT32_MAX, y_num = 0;
        for (int i = 0; i < n / 2; i++) {
            y_num += 2;
            nums[0][grid[i][i]]++;
            nums[0][grid[i][n - 1 - i]]++;
            grid[i][i] = grid[i][n - 1 - i] = -1;
        }
        for (int i = n / 2; i < n; i++) {
            y_num++;
            nums[0][grid[i][n / 2]]++;
            grid[i][n / 2] = -1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == -1) continue;
                nums[1][grid[i][j]]++;
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                int change = y_num - nums[0][i] + n * n - y_num - nums[1][j];
                res = min(res, change);
            }
        }
        return res;
    }
};