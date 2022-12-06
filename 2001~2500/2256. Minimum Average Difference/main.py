"""
Source: https://leetcode.com/problems/minimum-average-difference/
Date: 2022/12/4
Skill: Prefix Sum: the technique where we generate a prefix array, 
        and it's each element at (i + 1)th index stores the cumulative 
        sum of all array elements from index 0 to index i.
Runtime: 2739 ms, faster than 32.56%
Memory Usage: 30.8 MB, less than 7.41%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= nums.length <= 10^5
    0 <= nums[i] <= 10^5
"""

from typing import List
import math

class Solution:
    def minimumAverageDifference(self, nums: List[int]) -> int:
        sz, res, min_avg_diff = len(nums), 0, math.inf
        # Generate prefix and suffix sum arrays.
        prefix_sum, suffix_sum = [0]*(sz+1), [0]*(sz+1)
        
        for i in range(sz):
            prefix_sum[i+1] = prefix_sum[i]+nums[i]
            suffix_sum[sz-i-1] = suffix_sum[sz-i]+nums[sz-i-1]
        
        for i in range(sz-1):
            avg_diff = abs(prefix_sum[i+1]//(i+1)-suffix_sum[i+1]//(sz-i-1))
            if min_avg_diff > avg_diff:
                res = i
                min_avg_diff = avg_diff
                
        if abs(prefix_sum[sz]//(sz)) < min_avg_diff:
            res = sz-1
        
        return res