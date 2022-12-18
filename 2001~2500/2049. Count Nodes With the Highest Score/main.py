"""
Source: https://leetcode.com/problems/count-nodes-with-the-highest-score/description/
Date: 2022/12/10
Skill: 
Runtime: 1369 ms, faster than 93.55% 
Memory Usage: 123 MB, less than 24.73%
Time complexity: 
Space complexity: 
Constraints: 
    2 <= parents.length <= 10^5
    0 <= parents[i] <= n - 1 for i != 0
"""

from typing import List
import collections

class Solution:
    def countHighestScoreNodes(self, parents: List[int]) -> int:
        graph = collections.defaultdict(list)
        for node, parent in enumerate(parents): 
            graph[parent].append(node)
            
        sz = len(parents)
        cnt = collections.Counter()
        
        def count_nodes(root):
            sum, product = 1, 1
            for child in graph[root]:
                num = count_nodes(child)
                sum += num
                product *= num
            product *= max(1, sz-sum)
            cnt[product] += 1
            return sum
            
        count_nodes(0)
        return cnt[max(cnt.keys())]