/** 
 * Source: https://leetcode.com/problems/length-of-last-word/
 * Date: 2022/11/25
 * Skill: 0 ms, faster than 100.00%
 * Runtime: 6.5 MB, less than 51.39%
 * Memory Usage: 
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      
 */

#include <iostream>
#include <vector>
#include <utility>
#include <string> 
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int idx = s.length()-1, res = 0;
        while (s[idx] == ' ') idx--;
        while (idx>=0 && s[idx] != ' ') res++, idx--;
        return res;
    }
};

int main() {
    Solution s;
    
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();