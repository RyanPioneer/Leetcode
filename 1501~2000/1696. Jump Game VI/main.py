"""
Source: https://leetcode.com/problems/jump-game-vi/
Date: 2023/1/1
Skill: 
Runtime: 430 ms, faster than 82.7%
Memory Usage: 18 MB, less than 58.11%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= nums.length, k <= 10^5
    -10^4 <= nums[i] <= 10^4
"""

from typing import List
from collections import deque

class Solution:
    def maxResult(self, nums: List[int], k: int) -> int:
