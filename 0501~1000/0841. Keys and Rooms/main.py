"""
Source: https://leetcode.com/problems/keys-and-rooms/description/
Date: 2022/12/20
Skill: 
Runtime: 63 ms, faster than 97.56% 
Memory Usage: 14.4 MB, less than 57.55%
Time complexity: 
Space complexity: 
Constraints: 
    
"""

from typing import List
from collections import defaultdict

class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        stack, dict, visited = [0], defaultdict(int), 1
        dict[0] = 1
        while stack:
            cur = stack.pop()
            for key in rooms[cur]:
                if not dict[key]:
                    stack.append(key)
                    visited += 1
                    dict[key] = 1
                    
        return visited == len(rooms)