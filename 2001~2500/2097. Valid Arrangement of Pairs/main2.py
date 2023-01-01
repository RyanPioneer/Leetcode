"""
Source: https://leetcode.com/problems/valid-arrangement-of-pairs/description/
Date: 2022/12/19
Skill: Hierholzer's Algorithm
Runtime: 6873 ms, faster than 40% 
Memory Usage: 80.3 MB, less than 86.15%
Time complexity: 
Space complexity: 
Constraints: 
    
"""

from typing import List
from collections import defaultdict, deque, Counter

class Solution:
    def validArrangement(self, pairs: List[List[int]]) -> List[List[int]]:
        in_degrees = Counter()
        out_degrees = Counter()
        graph = defaultdict(list)
        for start, end in pairs:
            graph[start].append(end)
            in_degrees[end] += 1
            out_degrees[start] += 1
        
        start = pairs[0][0]
        for node, out_degree in out_degrees.items():
            if out_degree - in_degrees[node] == 1:
                start = node
                break
        
        path = deque()
        stack = [start]
        while stack:
            while graph[stack[-1]]:
                stack.append(graph[stack[-1]].pop())
            path.appendleft(stack.pop())
        
        result = []
        prev = path.popleft()
        while path:
            curr = path.popleft()
            result.append((prev, curr))
            prev = curr
        return result