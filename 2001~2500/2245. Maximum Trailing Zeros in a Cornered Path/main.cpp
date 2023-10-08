/**
 * Source: ibit.ly/lKkNC
 * Date: 2023/10/7
 * Skill:
 * Runtime: 259 ms, faster than 23.24% of C++ online submissions
 * Memory Usage: 275.68 MB, less than 15.77% of C++ online submissions
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
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<vector<int>>> rows(m, vector<vector<int>>(n)), cols(n, vector<vector<int>>(m));
        for (int i = 0; i < m; i++) {
            int two_cnt = count_two(grid[i][0]), five_cnt = count_five(grid[i][0]);
            rows[i][0] = {two_cnt, five_cnt};
            if (i == 0)
                cols[0][0] = {two_cnt, five_cnt};
            else
                cols[0][i] = {two_cnt + cols[0][i - 1][0], five_cnt + cols[0][i - 1][1]};
            for (int j = 1; j < n; j++) {
                int two_cnt = count_two(grid[i][j]), five_cnt = count_five(grid[i][j]);
                rows[i][j] = {two_cnt + rows[i][j - 1][0], five_cnt + rows[i][j - 1][1]};
                if (i == 0)
                    cols[j][i] = {two_cnt, five_cnt};
                else
                    cols[j][i] = {two_cnt + cols[j][i - 1][0], five_cnt + cols[j][i - 1][1]};
            }
        }
        res = min(rows[0][n - 1][0] + cols[0][m - 1][0] - rows[0][0][0], rows[0][n - 1][1] + cols[0][m - 1][1] - rows[0][0][1]);
        for (int i = 1; i < n - 1; i++) {
            vector<vector<int>> nums;
            nums.push_back(rows[0][i - 1]);
            nums.push_back({rows[0][n - 1][0] - rows[0][i][0], rows[0][n - 1][1] - rows[0][i][1]});
            for (auto j: nums) {
                int num = min(j[0] + cols[i][m - 1][0], j[1] + cols[i][m - 1][1]);
                res = max(res, num);
            }
        }
        int num = min(rows[0][n - 2][0] + cols[n - 1][m - 1][0], rows[0][n - 2][1] + cols[n - 1][m - 1][1]);
        res = max(res, num);
        for (int i = 1; i < m - 1; i++) {

        }

    }
    int count_two(int num) {
        int cnt = 0;
        while (num % 2 == 0) {
            cnt++;
            num /= 2;
        }
        return cnt;
    }
    int count_five(int num) {
        int cnt = 0;
        while (num % 5 == 0) {
            cnt++;
            num /= 5;
        }
        return cnt;
    }
};


int main() {
    Solution s;
    vector<int> nums{2, 3, 3, 2};
    vector<vector<int>> arr{{1,2}, {2,3}, {2,4}};
}