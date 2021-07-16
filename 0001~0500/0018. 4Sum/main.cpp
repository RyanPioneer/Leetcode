/** 
 * Source: https://leetcode.com/problems/4sum/
 * Date: 2021/7/17
 * Skill: Two Pointers
 * Runtime: 116 ms, faster than 24.91% of C++ online submissions
 * Memory Usage: 12.9 MB, less than 83.39% of C++ online submissions
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      1 <= nums.length <= 200
 *      -10^9 <= nums[i], target <= 10^9
 *      * the solution set must not contain duplicate triplets.
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n-3; i++) {
            if (i && nums[i] == nums[i-1])
                continue;
            for (int j = i+1; j < n-2; j++) {
                if (j != i+1 && nums[j] == nums[j-1])
                    continue;
                int l = j+1, r = n-1;
                while (l < r) {
                    if (nums[i] + nums[j] + nums[l] + nums[r] == target) {
                        ans.push_back({nums[i], nums[j], nums[l++], nums[r--]});
                        while (l < r && nums[l] == nums[l-1])
                            l++;
                        while (l < r && nums[r] == nums[r+1])
                            r--;
                    } else if (nums[i] + nums[j] + nums[l] + nums[r] > target) 
                        r--;
                    else
                        l++;
                }
            }
        }
        return ans;
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();