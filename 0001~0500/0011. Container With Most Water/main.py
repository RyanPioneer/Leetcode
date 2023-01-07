"""
Source: https://leetcode.com/problems/container-with-most-water/
Date: 2023/1/7
Skill: Greedy
Ref:
Runtime: 811 ms, faster than 71.20%
Memory Usage: 27.5 MB, less than 46.49%
Time complexity:
Space complexity:
Constraints:

"""

from typing import List, Optional

class Solution:
    def maxArea(self, height: List[int]) -> int:
        left, right, res = 0, len(height)-1, min(height[0], height[len(height)-1]) * (len(height)-1)
        while left < right:
            res = max(res, min(height[right], height[left]) * (right - left))
            if height[right] > height[left]: left += 1
            else: right -= 1

        return res