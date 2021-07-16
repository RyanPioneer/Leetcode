/** 
 * Source: https://leetcode.com/problems/minimum-path-sum/
 * Date: 2021/7/16
 * Skill: DP
 * Runtime: 8 ms, faster than 85.26% of C++ online submissions
 * Memory Usage: 10.1 MB, less than 37.28% of C++ online submissions
 * Space complexity: O(m*n)
 * Constraints: 
 *      m == grid.length
 *      n == grid[i].length
 *      1 <= m, n <= 200
 *      0 <= grid[i][j] <= 100
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size()+1, vector<int>(grid[0].size()+1, 0));
        for (int j = 1; j <= grid[0].size(); j++) 
            dp[1][j] = dp[1][j-1] + grid[0][j-1];
        for (int i = 1; i <= grid.size(); i++) 
            dp[i][1] = dp[i-1][1] + grid[i-1][0];
        for (int i = 2; i <= grid.size(); i++) {
            for (int j = 2; j <= grid[0].size(); j++) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1];
            }
        }
        return dp[grid.size()][grid[0].size()];
    }
};

int main() {
    vector<vector<int>> v1 = {{1,3,1}, {1,5,1}, {4,2,1}};
    Solution s;
    cout<<s.minPathSum(v1);
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();