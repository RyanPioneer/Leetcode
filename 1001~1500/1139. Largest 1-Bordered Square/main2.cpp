/**
 * Source: twtr.to/B8v63
 * Date: 2023/11/21
 * Skill:
 * Ref: twtr.to/eCnQc
 * Runtime: 8 ms, faster than 94.97% of C++ online submissions
 * Memory Usage: 10.94 MB, less than 99.44% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
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


#define SZ(X) ((int)(X).size())
#define ll long long
using namespace std;
const int MX = 1e2 + 1;


class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = SZ(grid), n = SZ(grid[0]), res = 0;
        int rows[MX][MX] = {0}, cols[MX][MX] = {0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    rows[i][j] = 1 + (j > 0 ? rows[i][j - 1] : 0);
                    cols[i][j] = 1 + (i > 0 ? cols[i - 1][j] : 0);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int small = min(rows[i][j], cols[i][j]);
                while (small > res) {
                    if (rows[i - small + 1][j] >= small && cols[i][j - small + 1] >= small) {
                        res = small;
                        break;
                    }
                    small--;
                }
            }
        }
        return res * res;
    }
};