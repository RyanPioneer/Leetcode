/**
 * Source: https://rb.gy/mpsh5
 * Date: 2023/9/19
 * Skill:
 * Runtime: 510 ms, faster than 46.48% of C++ online submissions
 * Memory Usage: 194.4 MB, less than 30.99% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int res = m * n, dir[5] = {0, 1, 0, -1, 0};
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (auto i: walls) {
            grid[i[0]][i[1]] = 2;
            res--;
        }
        for (auto i: guards) {
            grid[i[0]][i[1]] = 2;
            res--;
        }
        for (auto i: guards) {
            int x = i[0], y = i[1];
            for (int i = 0; i < 4; ++i) {
                int xx = x + dir[i], yy = y + dir[i + 1];
                while (check_feasible(xx, yy, m, n) && grid[xx][yy] != 2) {
                    if (grid[xx][yy] == 0) {
                        grid[xx][yy] = 1;
                        res--;
                    }
                    xx += dir[i]; yy += dir[i + 1];
                }
            }
        }
        return res;
    }
    bool check_feasible(int x, int y, int m, int n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }
};

int main() {
    Solution s;
    vector<int> nums2{8, 8, 9, 1, 6, 3, 0, 4, 1, 4, 1, 8, 0, 3, 1, 2, 7, 9, 3, 2, 5, 5, 2, 7, 9, 5, 2, 2};
    vector<vector<int>> arr1{{0, 0},
                             {1, 1},
                             {2, 3}};
    vector<vector<int>> arr2{{0, 1},
                             {2, 2},
                             {1, 4}};
    int res = s.countUnguarded(4,6,arr1, arr2);
    cout << res << endl;
}