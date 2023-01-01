"""
Source: https://leetcode.com/problems/possible-bipartition/description/
Date: 2022/12/21
Skill: DFS
Runtime: 719 ms, faster than 94.37 
Memory Usage: 21.7 MB, less than 39.75%
Time complexity: 
Space complexity: 
Constraints: 
    
"""

from typing import List

class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        color, neighbors = [-1 for i in range(n+1)], [[]for i in range(n+1)]
        for n1, n2 in dislikes:
            neighbors[n1].append(n2)
            neighbors[n2].append(n1)
        
        def dfs(cur, num):
            color[cur] = num%2
            for neighbor in neighbors[cur]:
                if color[neighbor] == -1:
                    if dfs(neighbor, (num+1)%2): return True
                elif color[neighbor] == num%2:
                    return True
            
            return False
            
        for i in range(1, n+1):
            if color[i] == -1 and neighbors[i]:
                if dfs(i, 0): return False
        
        return True
    
if "__name__" == "__main__":
    s = Solution
    print(s.possibleBipartition(s, 4, [[1,2],[1,3],[2,4]]))