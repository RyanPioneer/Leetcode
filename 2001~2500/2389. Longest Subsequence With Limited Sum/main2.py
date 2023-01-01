"""
Source: https://leetcode.com/problems/longest-subsequence-with-limited-sum/description/
Date: 2022/12/25
Skill: Prefix Sum + Binary Search
Runtime: 100 ms, faster than 98.25% 
Memory Usage: 14.2 MB, less than 79.61%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= n, m <= 1000
    1 <= nums[i], queries[i] <= 10^6
"""

from typing import List
from bisect import bisect

class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        nums.sort()
        for i in range(1, len(nums)):
            nums[i] += nums[i-1]
        res = []
        for query in queries:
            res.append(bisect.bisect_right(nums, query))
        return res