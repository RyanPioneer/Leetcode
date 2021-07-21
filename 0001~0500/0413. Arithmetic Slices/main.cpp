/** 
 * Source: https://leetcode.com/problems/arithmetic-slices/
 * Date: 2021/7/21
 * Skill: 
 * Runtime: 4 ms, faster than 62.35% of C++ online submissions
 * Memory Usage: 7.3 MB, less than 54.92% of C++ online submissions
 * Time complexity:
 * Space complexity: 
 * Constraints: 
 *      consists of at least three contiguous elements
 *      1 <= nums.length <= 5000
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int sum = 0;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2])
                ans[i] = ans[i-1] + 1;
            sum += ans[i];
        }
        return sum;
    }
};

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();