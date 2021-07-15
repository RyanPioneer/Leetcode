/** 
 * Source: https://leetcode.com/problems/valid-palindrome/
 * Date: 2021/7/15
 * Runtime: 4 ms
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints: 
 *      1 <= s.length <= 2 * 10^5
 *      s consists only of printable ASCII characters.
 */

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for (auto i:s) {
            if (i >= 'a' && i <= 'z') {
                str.push_back(i);
            } else if(i >= 'A' && i <= 'Z') {
                str.push_back('a'+i-'A');
            } else if(i >= '0' && i <= '9')
                str.push_back(i);
        }
        for (int i = 0; i < str.length(); i++)
            if (str[i] != str[str.length()-1-i])
                return false;
        return true;
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();