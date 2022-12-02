"""
Source: https://leetcode.com/problems/two-sum/
Date: 2022/2/18
Array: []
Dictionary: {}
"""

from typing import List
from functools import lru_cache
@lru_cache()

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {}
        for i, value in enumerate(nums):
            if target - value in seen:
                return [seen[target - value], i]
            else:
                seen[value] = i
            #print(i, value)
sol = Solution()               
ans = sol.twoSum([3,3], 6)
print(ans)

