"""
Source: https://leetcode.com/problems/all-paths-from-source-to-target/
Date: 2022/12/6
Skill: 
Runtime: 106 ms, faster than 86.69% 
Memory Usage: 15.6 MB, less than 97.56%
Time complexity: 
Space complexity: 
Constraints: 
    2 <= graph.length <= 15
    0 <= graph[i][j] < n
    graph[i][j] != i (i.e., there will be no self-loops).
    All the elements of graph[i] are unique.
    The input graph is guaranteed to be a DAG.
"""

from typing import List

class Solution:
    def allPathsSourceTarget(self,graph: List[List[int]]) -> List[List[int]]:
        res = []
        des = len(graph)-1
        
        def findPath(cur, path):
            if cur == des:
                res.append(path)
            else:
                for n in graph[cur]:
                    findPath(n,path+[n])
        findPath(0,[0])
        return res
    
if __name__ == '__main__': # 👈️ wrap in quotes
    s = Solution
    graph = [[1,2],[3],[3],[]]
    res = s.allPathsSourceTarget(graph)
    