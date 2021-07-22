/** 
 * Source: https://leetcode.com/problems/longest-palindromic-substring/solution/
 * Date: 2021/7/22
 * Skill: DP
 * Runtime: 380 ms, faster than 24.58% of C++ online submissions
 * Memory Usage: 29.9 MB, less than 39.09% of C++ online submissions
 * Time complexity:
 * Space complexity: 
 * Constraints: 
 *      1 <= s.length <= 1000
 */

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.length(), start = 0, length = 1;
        vector<vector<bool>> dp(sz, vector<bool>(sz+1, true));
        for (int len =  2; len <= sz; len++) {
            for (int i = 0; i+len-1 < sz; i++) {
                if (s[i] == s[i+len-1] && dp[i+1][len-2]) {
                    start = i;
                    length = len;
                } else {
                    dp[i][len] = false;
                }
            }
        }
        return s.substr(start, length);
    }
};


static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();