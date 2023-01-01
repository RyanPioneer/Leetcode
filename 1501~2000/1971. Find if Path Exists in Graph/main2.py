"""
Source: https://leetcode.com/problems/find-if-path-exists-in-graph/description/
Date: 2022/12/19
Skill: Disjoint Set Union (DSU)
Runtime: 2733 ms, faster than 71.48% 
Memory Usage: 103.6 MB, less than 87.73%
Time complexity: 
Space complexity: 
Constraints: 
    
"""

from typing import List

class UnionFind:
    def __init__(self, n) -> None:
        self.root = list(range(n))
        self.rank = [1]*n
        
    def find(self, n):
        if n != self.root[n]:
            self.root[n] = self.find(self.root[n])
        return self.root[n]
    
    def union(self, n1, n2):
        root1, root2 = self.find(n1), self.find(n2)
        if root1 != root2:
            if self.rank[root1] < self.rank[root2]:
                root1, root2 = root2, root1
            self.rank[root1] += self.rank[root2]
            self.root[root2] = root1

class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        group = UnionFind(n)
        for edge in edges:
            group.union(edge[0], edge[1])
        
        return group.find(source) == group.find(destination)