/**
 * Source: twtr.to/B8v63
 * Date: 2023/11/20
 * Skill:
 * Runtime: 15 ms, faster than 60.00% of C++ online submissions
 * Memory Usage: 11.03 MB, less than 97.71% of C++ online submissions
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
        int m = SZ(grid), n = SZ(grid[0]), res = 0, presum[MX][MX] = {0};
        for (int i = 0; i < m; i++) {
            if (grid[i][0]) res = 1;
            presum[i + 1][1] = presum[i][1] + grid[i][0];
        }
        for (int i = 0; i < n; i++) {
            if (grid[0][i]) res = 1;
            presum[1][i + 1] = presum[1][i] + grid[0][i];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j]) res = 1;
                presum[i + 1][j + 1] = presum[i + 1][j] + presum[i][j + 1] - presum[i][j] + grid[i][j];
            }
        }
        for (int len = min(m, n); len > 1; len--) {
            for (int i = 0; i + len <= m; i++) {
                for (int j = 0; j + len <= n; j++) {
                    int total = presum[i + len][j + len] - presum[i][j + len] - presum[i + len][j] + presum[i][j];
                    int inner = presum[i + len - 1][j + len - 1] - presum[i + 1][j + len - 1] - presum[i + len - 1][j + 1] + presum[i + 1][j + 1];
                    if (total - inner == 4 * (len - 1)) return len * len;
                }
            }
        }
        return res * res;
    }
};