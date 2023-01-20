"""
Source: https://leetcode.com/problems/non-decreasing-subsequences/
Date: 2023/1/20
Skill:
Ref:
Runtime: 1203 ms, faster than 8.60%
Memory Usage: 22.5 MB, less than 32.34%
Time complexity:
Space complexity:
Constraints:
    -100 <= nums[i] <= 100
"""

from typing import List, Optional
from collections import defaultdict

class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        sz, res = len(nums), set()
        for bitmask in range(1, 1 << sz):
            sequence = [nums[i] for i in range(sz) if bitmask >> i & 1]
            if len(sequence) >= 2 and all(sequence[i] <= sequence[i+1] for i in range(len(sequence)-1)):
                res.add(tuple(sequence))
        return res