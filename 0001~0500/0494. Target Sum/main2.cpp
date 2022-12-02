/** 
 * Source: https://leetcode.com/problems/target-sum/
 * Date: 2022/7/18
 * Skill: Dynamic Programming
 * Runtime: 45 ms, faster than 43.78%
 * Memory Usage: 22 MB, less than 26.56%
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
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0, len = nums.size();
        for (int i : nums)
            sum += i;
        if (abs(target) > sum)
            return 0;
        vector<int> vec(2*sum+1, 0);
        vec[sum] = 1;
        for (int i = 0; i < len; i++) {
            vector<int> tmp(2*sum+1, 0);
            for (int j = nums[i]; j <= 2*sum-nums[i]; j++) {
                if (vec[j]) {
                    tmp[j+nums[i]] += vec[j];
                    tmp[j-nums[i]] += vec[j];
                }
            }
            swap(vec,tmp);
        }
        return vec[target+sum];
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