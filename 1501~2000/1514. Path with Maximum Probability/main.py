"""
Source: https://leetcode.com/problems/path-with-maximum-probability/
Date: 2022/12/30
Skill: Djikstra Algorithm
Runtime: 675 ms, faster than 97.49%
Memory Usage: 26 MB, less than 70.39%
Time complexity:
Space complexity:
Constraints:
    2 <= n <= 10^4
    0 <= succProb[i] <= 1
"""

from typing import List, Optional
import heapq

class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        myMap = [[] for i in range(n)] #edge, probability
        prob = [0 for i in range(n)]
        for i in range(len(edges)):
            myMap[edges[i][0]].append((edges[i][1], succProb[i]))
            myMap[edges[i][1]].append((edges[i][0], succProb[i]))

        h = [(-1.0, start)]
        heapq.heapify(h)
        while h:
            probability, node = heapq.heappop(h)
            if node == end:
                return -probability
            if prob[node] != 0: continue
            prob[node] = probability
            for neighbor in myMap[node]:
                if prob[neighbor[0]] == 0:
                    heapq.heappush(h, (probability*neighbor[1], neighbor[0]))

        return 0