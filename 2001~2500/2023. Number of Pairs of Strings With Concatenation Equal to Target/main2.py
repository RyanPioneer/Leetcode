"""
Source: https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/description/
Date: 2023/1/6
Skill:
Runtime: 55 ms, faster than 77.21%
Memory Usage: 13.9 MB, less than 73.31%
Time complexity:
Space complexity:
Constraints:

"""

from typing import List
from collections import Counter

class Solution:
    def numOfPairs(self, nums: List[str], target: str) -> int:
        res, cnt = 0, Counter(nums)
        for key, value in cnt.items():
            if target.startswith(key):
                if key == target[len(key):]: res += value * (value-1)
                else: res += value * cnt[target[len(key):]]

        return res