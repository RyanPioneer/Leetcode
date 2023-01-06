"""
Source: https://leetcode.com/problems/jump-game-vi/
Date: 2023/1/1
Skill: Dynamic Programming, Sliding Window, Monotonic Queue
Runtime: 973 ms, faster than 97.1%
Memory Usage: 27.7 MB, less than 69.27%
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
        q = deque([0])
        for i in range(1, len(nums)):
            nums[i] += nums[q[0]]
            while q and nums[q[-1]] < nums[i]: q.pop()
            if q and i - q[0] == k: q.popleft()
            q.append(i)
        return nums[len(nums)-1]