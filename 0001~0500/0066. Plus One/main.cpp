/** 
 * Source: https://leetcode.com/problems/plus-one/
 * Date: 2022/11/25
 * Skill: 
 * Runtime: 0 ms, faster than 100.00%
 * Memory Usage: 8.8 MB, less than 62.53%
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
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size()-1; i >= 0; i--) {
            if (digits[i] != 9) {
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0;
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
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