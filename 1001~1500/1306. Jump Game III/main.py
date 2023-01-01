"""
Source: https://leetcode.com/problems/jump-game-iii/
Date: 2022/12/26
Skill: 
Runtime: 294 ms, faster than 96.52% 
Memory Usage: 20.7 MB, less than 75.61%
Time complexity: 
Space complexity: 
Constraints: 
    
"""

from typing import List

class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        stack, vec, sz = [start], [0 for i in range(len(arr))], len(arr)
        vec[start] = 1
        if arr[start] == 0: return True
        while stack:
            cur = stack.pop()
            if cur+arr[cur] < sz and not vec[cur+arr[cur]]:
                if arr[cur+arr[cur]] == 0: return True
                vec[cur+arr[cur]] = 1
                stack.append(cur+arr[cur])
            if cur-arr[cur] >= 0 and not vec[cur-arr[cur]]:
                if arr[cur-arr[cur]] == 0: return True
                vec[cur-arr[cur]] = 1
                stack.append(cur-arr[cur])
        
        return False