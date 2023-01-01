"""
Source: https://leetcode.com/problems/daily-temperatures/
Date: 2022/12/18
Skill: 
Runtime: 3693 ms, faster than 29.38% 
Memory Usage: 28.6 MB, less than 57.30%
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
        for index in range(len(temperatures)-1, -1, -1):
            while stack and temperatures[stack[-1]]<=temperatures[index]:
                stack.pop()
            if stack: ans[index] = stack[-1]-index
            stack.append(index)
        return ans