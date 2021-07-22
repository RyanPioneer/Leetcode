/** 
 * Source: https://leetcode.com/problems/longest-palindromic-substring/solution/
 * Date: 2021/7/22
 * Skill: Manacher's Algorithm
 * Reference: https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-1/
 * Runtime: 16 ms, faster than 91.35% of C++ online submissions
 * Memory Usage: 9.3 MB, less than 61.90% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints: 
 *      1 <= s.length <= 1000
 */

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string input) {
        string s = "#";
        for (char c: input)
            s += c, s += '#';
        int id = 0, maxright = 0, rescenter = 0, reslen = 0;
        vector<int> r(s.size(), 0);
        for (int i = 1; i < s.size() - 1; i++) {
            r[i] = maxright > i ? min(r[2 * id - i], maxright - i) : 1;
            while (i - r[i] >= 0 && i + r[i] < s.size() && s[i + r[i]] == s[i - r[i]]) r[i] ++;
            r[i] --;
            if (i + r[i] > maxright) maxright = i + r[i], id = i;
            if (r[i] > reslen) reslen = r[i], rescenter = i;
        }
        return input.substr((rescenter - reslen) / 2, reslen);
    }
};

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();