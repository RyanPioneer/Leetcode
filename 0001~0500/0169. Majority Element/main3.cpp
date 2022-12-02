/** 
 * Source: https://leetcode.com/problems/majority-element/
 * Date: 2022/11/30
 * Skill: Bit Manipulation
 * Runtime: 37 ms, faster than 63.00% 
 * Memory Usage: 19.6 MB, less than 60.91%
 * Time complexity: O(nlogC), C is the max absolute value in nums, i.e., 10^5 in this problem. 
 *      We enumerate all logC bits for each number in nums.
 * Space complexity: O(1)
 * Constraints: 
 *      -10^9 <= nums[i] <= 10^9
 */

#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, sz = nums.size();
        for (int i = 0; i < 32; i++) {
            int b = 1<<i;
            int count = 0;
            for (auto n : nums) {
                if ((n&b) != 0)
                    count++;
            }
            if (count > sz/2)
                res |= b;
        }
        return res;
    }
};


static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();