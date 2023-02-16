"""
Source: https://leetcode.com/problems/add-edges-to-make-degrees-of-all-nodes-even/
Date: 2023/2/16
Skill:
Runtime: 1690 ms, faster than 71.89%
Memory Usage: 65.9 MB, less than 31.85%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def isPossible(self, n: int, edges: List[List[int]]) -> bool:
        graph, odd_node = [set() for _ in range(n)], []
        for edge in edges:
            graph[edge[0]-1].add(edge[1]-1)
            graph[edge[1]-1].add(edge[0]-1)

        for i in range(n):
            if len(graph[i]) % 2 == 1:
                odd_node.append(i)

        if len(odd_node) == 0:
            return True

        elif len(odd_node) == 4:
            if ((odd_node[1] not in graph[odd_node[0]]
                    and odd_node[2] not in graph[odd_node[3]])
                    or (odd_node[2] not in graph[odd_node[0]]
                    and odd_node[1] not in graph[odd_node[3]])
                    or (odd_node[3] not in graph[odd_node[0]]
                    and odd_node[1] not in graph[odd_node[2]])):
                return True

        elif len(odd_node) == 2:
            if odd_node[1] not in graph[odd_node[0]]:
                return True
            else:
                for i in range(n):
                    if (i not in odd_node
                            and i not in graph[odd_node[0]]
                            and i not in graph[odd_node[1]]):
                        return True

        return False


if __name__ == "__main__":
    s = Solution