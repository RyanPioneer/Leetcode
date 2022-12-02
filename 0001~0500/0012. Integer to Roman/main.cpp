/**
 * Source: https://leetcode.com/problems/integer-to-roman/
 * Date: 2022/7/12
 * Skill:
 * Runtime:
 * Memory Usage:
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      1 <= num <= 3999
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<string> romans = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int> nums{1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string s;
        for (int i = 0; i < nums.size(); i++) {
            while (num >= nums[i]) {
                s.append(romans[i]);
                num -= nums[i];
            }
        }
        return s;
    }
};

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();