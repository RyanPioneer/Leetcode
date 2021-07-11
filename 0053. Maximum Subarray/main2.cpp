// Source: https://leetcode.com/problems/maximum-subarray/
// Date: 2021/7/11
// Kadane’s Algorithm (Dynamic Programming or Greedy )
// Reference: https://medium.com/@rsinghal757/kadanes-algorithm-dynamic-programming-how-and-why-does-it-work-3fd8849ed73d
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // local_maximum at index i is the maximum of nums[i] 
        // and the sum of nums[i] and local_maximum at index i-1
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