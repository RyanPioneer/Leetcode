/** 
 * Source: https://leetcode.com/problems/valid-palindrome/
 * Date: 2021/7/15
 * Runtime: 0 ms
 * Time complexity: O(n)
 * Space complexity: O(1)
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
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
            while (isalnum(s[i]) == false && i < j) 
                i++; // Increment left pointer if not alphanumeric
            while (isalnum(s[j]) == false && i < j) 
                j--; // Decrement right pointer if no alphanumeric
            if (toupper(s[i]) != toupper(s[j])) 
                return false; // Exit and return error if not match
        }
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