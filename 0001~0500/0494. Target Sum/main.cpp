/** 
 * Source: https://leetcode.com/problems/target-sum/
 * Date: 2022/7/18
 * Skill: Recursion with Memoization
 * Runtime: 15 ms, faster than 76.42%
 * Memory Usage: 22.4 MB, less than 24.93%
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      1 <= nums.length <= 20
 *      0 <= nums[i] <= 1000
 *      0 <= sum(nums[i]) <= 1000
 *      -1000 <= target <= 1000
 */

#include <iostream>
#include <vector> 
#include <utility>
#include <unordered_map>
//#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int total;
    int findTargetSumWays(vector<int>& nums, int target) {
        total = 0;
        for (auto i : nums)
            total += i;
        vector<vector<int>> memo{nums.size(), vector<int>(2*total+1, INT_MIN)};
        return calculate(nums, target, 0, 0, memo);
    }

    int calculate(vector<int>& nums, int target, int index, int sum, vector<vector<int>>& memo) {
        if (index == nums.size())
            return (sum == target)?1:0;
        if (memo[index][sum+total] != INT_MIN) 
            return memo[index][sum+total];
        int add = calculate(nums, target, index+1, sum+nums[index], memo);
        int sub = calculate(nums, target, index+1, sum-nums[index], memo);
        return memo[index][sum+total] = add + sub;
    }
};

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();