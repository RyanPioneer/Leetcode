/** 
 * Source: https://leetcode.com/problems/perfect-squares/
 * Date: 2022/11/22
 * Skill: Dynamic Programming
 * Runtime: 272 ms, faster than 64.85% 
 * Memory Usage: 9.2 MB, less than 44.02%
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      1 <= n <= 10^4
 */

#include <iostream>
#include <vector>
#include <utility>
#include <string> 
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        for (int i = 0; i <= n; i++)
            dp[i] = i;
        for (int i = 2; i*i <= n; i++) {
            for (int j = i*i; j <= n; j++) 
                dp[j] = dp[j-i*i]+1<dp[j]?dp[j-i*i]+1:dp[j];
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    cout << s.numSquares(300);
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();