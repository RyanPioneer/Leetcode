/** 
 * Source: https://leetcode.com/problems/concatenation-of-array/
 * Date: 2022/11/29
 * Skill: 
 * Runtime: 7 ms, faster than 96.45%
 * Memory Usage:  12.8 MB, less than 40.44%
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      
 */

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        for (int i = 0, sz = nums.size(); i < sz; i++) {
            nums.push_back(nums[i]);
        }
        return nums;
    }
};


static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();