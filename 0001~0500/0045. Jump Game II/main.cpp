/**
 * Source: https://leetcode.com/problems/jump-game-ii/
 * Date: 2022/7/11
 * Skill:
 * Runtime:
 * Memory Usage:
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> ans(nums.size(), INT_MAX);
        ans[0] = 0;
        for (int i = 0; i < nums.size()-1; i++) 
            for (int j = 1; j <= nums[i] && i+j<nums.size(); j++) 
                ans[i+j] = (ans[i]+1 < ans[i+j])?ans[i]+1:ans[i+j];
        return ans[nums.size()-1];
    }
};

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();
