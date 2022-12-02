/** 
 * Source: https://leetcode.com/problems/majority-element/
 * Date: 2022/11/30
 * Skill: 
 * Runtime: 11 ms, faster than 99.57%
 * Memory Usage: 19.6 MB, less than 15.21%
 * Time complexity: 
 * Space complexity: 
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
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
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