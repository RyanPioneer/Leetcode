"""
Source: https://leetcode.com/problems/intersection-of-multiple-arrays/
Date: 2022/12/20
Skill: 
Runtime: 80 ms, faster than 81.64% 
Memory Usage: 14.3 MB, less than 26.93%
Time complexity: 
Space complexity: 
Constraints: 
   
"""

from typing import List
from collections import Counter

class Solution:
    def intersection(self, nums: List[List[int]]) -> List[int]:
        cnt, res = Counter(), []
        for row in nums:
            for num in row:
                cnt[num] += 1
        for num, count in cnt.items():
            if count == len(nums):
                res.append(num)
        
        return sorted(res)