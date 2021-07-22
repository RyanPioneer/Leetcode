/** 
 * Source: https://leetcode.com/problems/palindromic-substrings/
 * Date: 2021/7/22
 * Skill: 
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.2 MB, less than 87.52% of C++ online submissions
 * Time complexity: O(n^2)
 * Space complexity: O(1)
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
        int len = s.length(), ans = 0;
        for (int i = 0; i < len; i++) {
            for (int j = 0; i - j >= 0 && i + j < len && s[i+j] == s[i-j]; j++) ans++;
            for (int j = 0; i - 1 - j >= 0 && i + j < len && s[i-1-j] == s[i+j]; j++) ans++;
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