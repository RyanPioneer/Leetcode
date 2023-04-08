"""
Source: https://leetcode.com/problems/clone-graph/
Date: 2023/4/8
Skill:
Ref:
Runtime: 32 ms, faster than 94.54%
Memory Usage: 14.3 MB, less than 65.43%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the graph is in the range [0, 100].
    Node.val is unique for each node.
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return None
        head = Node(node.val)
        visited, q = [0 for _ in range(101)], deque([(node, head)])
        visited[node.val] = head
        while q:
            old_node, new_node = q.pop()
            for neighbor in old_node.neighbors:
                if visited[neighbor.val] == 0:
                    next_node = Node(neighbor.val)
                    visited[neighbor.val] = next_node
                    q.append((neighbor, next_node))
                new_node.neighbors.append(visited[neighbor.val])

        return head


if __name__ == "__main__":
    s = Solution()
