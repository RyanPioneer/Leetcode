"""
Source: https://leetcode.com/problems/find-if-path-exists-in-graph/description/
Date: 2022/12/19
Skill: 
Runtime: 1954 ms, faster than 88.27% 
Memory Usage: 103.7 MB, less than 87.73%
Time complexity: 
Space complexity: 
Constraints: 
    
"""

from typing import List

class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        nodes, visited, stack = [set() for i in range(n)], [0]*n, [source]
        visited[source] = 1
        for edge in edges:
            nodes[edge[0]].add(edge[1])
            nodes[edge[1]].add(edge[0])
        
        while stack:
            cur = stack.pop()
            if cur == destination: return True
            for n in nodes[cur]:
                if not visited[n]:
                    visited[n] = 1
                    stack.append(n)
                    
        return False
    
if __name__ == "__main__":
    s = Solution
    res = s.validPath(s, 6, [[0,1],[0,2],[3,5],[5,4],[4,3]], 0, 5)
    print(res)