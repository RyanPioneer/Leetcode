"""
Source: https://rb.gy/cg3rm
Date: 2023/8/7
Skill:
Ref:
Runtime: 1409 ms, faster than 93.60%
Memory Usage: 43.52 MB, less than 100.00%
Time complexity:
Space complexity:
Constraints:

"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def minimumTime(self, n: int, relations: List[List[int]], time: List[int]) -> int:
        indegree, next = [0 for _ in range(n)], [[] for _ in range(n)]
        for relation in relations:
            indegree[relation[1] - 1] += 1
            next[relation[0] - 1].append(relation[1] - 1)
        q, deadline, res = deque(), [0 for _ in range(n)], 0
        for i in range(n):
            if indegree[i] == 0:
                q.append(i)
        while q:
            idx = q.popleft()
            deadline[idx] += time[idx]
            for neighbor in next[idx]:
                deadline[neighbor] = max(deadline[neighbor], deadline[idx])
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    q.append(neighbor)

        return max(deadline)


if __name__ == "__main__":
    s = Solution()
