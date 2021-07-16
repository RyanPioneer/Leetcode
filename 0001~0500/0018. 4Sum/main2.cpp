/** 
 * Source: https://leetcode.com/problems/4sum/
 * Date: 2021/7/17
 * Skill: Two Pointers
 * Runtime: 8 ms, faster than 98.53% of C++ online submissions
 * Memory Usage: 13.6 MB, less than 19.86% of C++ online submissions
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      1 <= nums.length <= 200
 *      -10^9 <= nums[i], target <= 10^9
 *      * the solution set must not contain duplicate triplets.
 */

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        return kSum(nums, target, 0, 4);
    }
    vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k) {
        vector<vector<int>> res;
        if (start == nums.size() || nums[start] * k > target || target > nums.back() * k)
            return res;
        if (k == 2)
            return twoSum(nums, target, start);
        for (int i = start; i < nums.size(); ++i)
            if (i == start || nums[i - 1] != nums[i])
                for (auto &set : kSum(nums, target - nums[i], i + 1, k - 1)) {
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(set), end(set));
                }
        return res;
    }
    vector<vector<int>> twoSum(vector<int>& nums, int target, int start) {
        vector<vector<int>> res;
        int lo = start, hi = nums.size() - 1;
        while (lo < hi) {
            int sum = nums[lo] + nums[hi];
            if (sum < target || (lo > start && nums[lo] == nums[lo - 1]))
                ++lo;
            else if (sum > target || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1]))
                --hi;
            else
                res.push_back({ nums[lo++], nums[hi--]});
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