"""
Source: https://leetcode.com/problems/valid-arrangement-of-pairs/description/
Date: 2022/12/19
Skill: Hierholzer's Algorithm
Runtime: 3054 ms, faster than 78.46% 
Memory Usage: 169.3 MB, less than 26.15%
Time complexity: 
Space complexity: 
Constraints: 
    
"""

from typing import List
from collections import defaultdict

class Solution:
    def validArrangement(self, pairs: List[List[int]]) -> List[List[int]]:
        res, self.path, in_degree, out_degree, edges, start = [], [], defaultdict(int), defaultdict(int), defaultdict(list), pairs[0][0]
        for pair in pairs:
            in_degree[pair[1]] += 1
            out_degree[pair[0]] += 1
            edges[pair[0]].append(pair[1])
        
        for index, degree in out_degree.items():
            if degree-in_degree[index] == 1:
                start = index
                break

        def dfs(s):
            while edges[s]:
                next_node = edges[s].pop()
                dfs(next_node)
            self.path.append(s)
            
        dfs(start)
        self.path.reverse()
        for i in range(len(self.path)-1):
            res.append([self.path[i], self.path[i+1]])
            
        return res
        
if __name__ == "__main__":
    s = Solution
    res = s.validArrangement(s, [[5,1],[4,5],[11,9],[9,4]])