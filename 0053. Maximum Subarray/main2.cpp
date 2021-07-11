// Source: https://leetcode.com/problems/maximum-subarray/
// Date: 2021/7/11
// Greedy Algo
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], sum = nums[0];
        for(int i = 1; i < nums.size(); i ++) {
            if(sum + nums[i] < nums[i]) 
                sum = nums[i];
            else sum += nums[i];
            res = max(res, sum);
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