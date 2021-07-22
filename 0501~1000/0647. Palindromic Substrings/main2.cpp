/** 
 * Source: https://leetcode.com/problems/palindromic-substrings/
 * Date: 2021/7/22
 * Skill: DP
 * Runtime: 16 ms, faster than 50.46% of C++ online submissions 
 * Memory Usage: 7.7 MB, less than 49.13% of C++ online submissions
 * Time complexity: O(n^2)
 * Space complexity: O(n^2)
 * Constraints: 
 *      1 <= s.length <= 1000
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int sz = s.length(), ans = s.length();
        vector<vector<bool>> dp(sz, vector<bool>(sz+1, true));
        for (int len = 2; len <= sz; len++) {
            for (int i = 0; i+len-1 < sz; i++) {
                if (s[i] == s[i+len-1] && dp[i+1][len-2]) ans++;
                else dp[i][len] = false;
            }
        }
        return ans;
    }
};

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();