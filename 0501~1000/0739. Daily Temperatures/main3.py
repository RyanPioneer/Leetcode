"""
Source: https://leetcode.com/problems/daily-temperatures/
Date: 2022/12/18
Skill: 
Runtime: 1555 ms, faster than 76.1% 
Memory Usage: 28.9 MB, less than 47.40%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= temperatures.length <= 10^5
    30 <= temperatures[i] <= 100
"""

from typing import List

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        ans = [0]*len(temperatures)
        for cur in range(len(temperatures)-2, -1, -1):
            next = cur+1
            while next < len(temperatures) and temperatures[next] <= temperatures[cur]:
                next += ans[next] if ans[next] > 0 else len(temperatures)
            ans[cur] = next-cur if next < len(temperatures) else 0
            
        return ans