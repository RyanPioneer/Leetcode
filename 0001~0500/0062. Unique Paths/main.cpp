/** 
 * Source: https://leetcode.com/problems/unique-paths/
 * Date: 2021/7/22
 * Skill: DP
 * Runtime:  0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.2 MB, less than 41.12% of C++ online submissions
 * Time complexity:
 * Space complexity: 
 * Constraints: 
 * 
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for (int i = 1; i < m; i++) 
            for (int j = 1; j < n; j++) dp[j] += dp[j-1];
        return dp[n-1];
    }
};

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();