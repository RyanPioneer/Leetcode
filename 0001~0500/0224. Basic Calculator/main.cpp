/** 
 * Source: https://leetcode.com/problems/basic-calculator/
 * Date: 2022/11/20
 * Skill: 
 * Runtime: 
 * Memory Usage: 
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      Every number and running calculation will fit in a signed 32-bit integer.
 *      There will be no two consecutive operators in the input.
 */

#include <iostream>
#include <stack>
#include <utility>
#include <string> 
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int res = 0;
        stack<pair<char,int>> mystack;
        for (int i = 0; i < s.length(); i++) {

        }
    }

};

int main() {
    
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();