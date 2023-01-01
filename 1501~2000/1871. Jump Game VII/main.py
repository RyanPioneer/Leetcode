"""
Source: https://leetcode.com/problems/jump-game-vii/
Date: 2023/1/1
Skill: 
Runtime: 430 ms, faster than 82.7%
Memory Usage: 18 MB, less than 58.11%
Time complexity: 
Space complexity: 
Constraints: 
    s[0] == '0'
    1 <= minJump <= maxJump < s.length
"""

from typing import List
from collections import deque

class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        if s[len(s)-1] == '1': return False
        q = deque([0])
        mx = 0 #! important!
        while q:
            cur = q.popleft()
            for i in range(max(mx+1, cur+minJump), min(cur+maxJump+1, len(s))):
                if s[i] == '0':
                    if i == len(s)-1: return True
                    q.append(i)
            mx = max(mx, min(cur+maxJump, len(s)-1))

        return False