/** 
 * Source: https://leetcode.com/problems/subsets/
 * Date: 2022/7/12
 * Skill: Recursive
 * Runtime:  
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      1 <= nums.length <= 10
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> vec;
        vector<vector<int>> ans;
        subsets2(nums, vec, ans);
        return ans;
    }

    void subsets2(vector<int> nums, vector<int> vec, vector<vector<int>> &ans) {
        if (nums.size() == 1) {
            ans.push_back(vec);
            vec.push_back(nums[0]);
            ans.push_back(vec);
        } else {
            int num = nums[0];
            nums.erase(nums.begin());
            subsets2(nums, vec, ans);
            vec.push_back(num);
            subsets2(nums, vec, ans);
        }
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();