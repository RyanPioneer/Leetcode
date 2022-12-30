"""
Source: https://leetcode.com/problems/daily-temperatures/
Date: 2022/12/18
Skill: 
Runtime: 1408 ms, faster than 91.18% 
Memory Usage: 29.3 MB, less than 29.13%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= temperatures.length <= 10^5
    30 <= temperatures[i] <= 100
"""

from typing import List

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack, ans = [], [0]*len(temperatures)
        for i, n in enumerate(temperatures):
            while stack and stack[-1][1] < n:
                ans[stack[-1][0]] = i - stack[-1][0]
                stack.pop()
            stack.append((i, n))
            
        return ans