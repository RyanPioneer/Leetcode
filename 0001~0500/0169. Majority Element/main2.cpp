/** 
 * Source: https://leetcode.com/problems/majority-element/
 * Date: 2022/11/30
 * Skill: Boyer-Moore Voting Algorithm
 * Runtime: 18 ms, faster than 94.90%
 * Memory Usage: 19.7 MB, less than 15.21% 
 * Time complexity: O(n)
 * Space complexity: O(1)
 * Constraints: 
 *      
 */

#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, res = nums[0];
        for (auto i : nums) {
            if (res == i) 
                count++;
            else {
                if (!count) {
                    count++;
                    res = i;
                } else
                    count--;
            }
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