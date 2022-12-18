"""
Source: https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three/
Date: 2022/12/9
Skill: 
Runtime: 88 ms, faster than 87.8% 
Memory Usage: 13.9 MB, less than 93.48%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= nums.length <= 1000
"""

from typing import List

class Solution:
    def averageValue(self, nums: List[int]) -> int:
        res, sz = 0, 0
        for n in nums:
            if n%6 == 0:
                res += n
                sz += 1
        if sz == 0:
            return 0
        return res//sz