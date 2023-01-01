"""
Source: https://leetcode.com/problems/longest-subsequence-with-limited-sum/description/
Date: 2022/12/25
Skill: Sort and Count
Runtime: 388 ms, faster than 41.26% 
Memory Usage: 14.2 MB, less than 79.61%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= n, m <= 1000
    1 <= nums[i], queries[i] <= 10^6
"""

from typing import List
import math

class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        nums.sort()
        nums.append(math.inf)
        res = []
        for q in queries:
            for i in range(len(nums)):
                if q<nums[i]:
                    res.append(i)
                    break
                q -= nums[i]
        
        return res