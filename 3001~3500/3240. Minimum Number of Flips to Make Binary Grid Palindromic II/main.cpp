/**
 * Source: jpeg.ly/MZIjp
 * Date: 2025/1/29
 * Skill:
 * Ref:
 * Runtime: 3 ms, faster than 69.23% of C++ online submissions
 * Memory Usage: 193.89 MB, less than 81.20% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      1 <= m * n <= 2 * 10 ** 5
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
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), cnt, res = 0;
        
        for (int i = 0; i < m/2; i++) {
            for (int j = 0; j < n/2; j++) {
                cnt = grid[i][j] + grid[i][n-1-j] + grid[m-1-i][j] + grid[m-1-i][n-1-j];
                res += min(cnt, 4-cnt);
            }
        }

        if (m % 2 && n % 2) {
            res += grid[m/2][n/2];
        }

        int diff = 0, oneNum = 0;

        if (m % 2) {
            for (int j = 0; j < n/2; j++) {
                if (grid[m/2][j] != grid[m/2][n-1-j]) {
                    diff++;
                } else {
                    oneNum += grid[m/2][j] * 2;
                }
            }
        }

        if (n % 2) {
            for (int i = 0; i < m/2; i++) {
                if (grid[i][n/2] != grid[m-1-i][n/2]) {
                    diff++;
                } else {
                    oneNum += grid[i][n/2] * 2;
                }
            }
        }

        return res + (diff ? diff : oneNum % 4);
    }
};
