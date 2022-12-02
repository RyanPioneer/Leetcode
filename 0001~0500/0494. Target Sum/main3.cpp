/** 
 * Source: https://leetcode.com/problems/target-sum/
 * Ref: https://www.youtube.com/watch?v=zks6mN06xdQ&ab_channel=HuaHua
 * Date: 2022/7/19
 * Skill: Subset Sum
 * Runtime: 14 ms, faster than 79.00%
 * Memory Usage: 12.3 MB, less than 39.61%
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
#include <numeric>
//#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //Sum(P)+Sum(N) = Sum(nums), Sum(P)-Sum(N) = target
        //Sum(P) = (Sum(nums)+target)/2
        target = abs(target);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (target > sum || (target+sum)%2 != 0)
          return 0;
        vector<int> dp((target+sum)/2+1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
          vector<int> tmp(dp);
          for (int j = 0; j <= (target+sum)/2-nums[i]; j++) {
            if (dp[j])
              tmp[j+nums[i]] += dp[j];
          }
          swap(dp ,tmp);
        }
        return dp[(target+sum)/2];
    }
};

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    //std::cout.tie(nullptr);
    return nullptr;
}();