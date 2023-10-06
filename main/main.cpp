/**
 * Source: ibit.ly/lKkNC
 * Date: 2023/10/6
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
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> rows(m), cols(n);
        for (int i = 0; i < m; i++) {
            int two_cnt = 0, five_cnt = 0;
            int num = grid[i][0], num2 = grid[i][0];
            while (num % 2 == 0) {
                two_cnt++;
                num /= 2;
            }
            while (num2 % 5 == 0) {
                five_cnt++;
                num2 /= 5;
            }
            rows[i][0] = {two_cnt, five_cnt};
            if (i == 0) {
                cols[0][0] =
            }
            for (int j = 1; j < n; j++) {
                int two_cnt = 0, five_cnt = 0;
                int num = grid[i][j], num2 = grid[i][j];
                while (num % 2 == 0) {
                    two_cnt++;
                    num /= 2;
                }
                while (num2 % 5 == 0) {
                    five_cnt++;
                    num2 /= 5;
                }
                rows[i][j] = {two_cnt + rows[i][j - 1][0], five_cnt + rows[i][j - 1][1]};
            }
        }
    }
};


int main() {
    Solution s;
    vector<int> nums{2, 3, 3, 2};
    vector<vector<int>> arr{{1,2}, {2,3}, {2,4}};
}