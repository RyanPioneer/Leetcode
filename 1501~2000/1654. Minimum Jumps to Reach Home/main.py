"""
Source: https://rb.gy/oiiql
Date: 2023/7/23
Skill:
Ref:
Runtime: 142 ms, faster than 35.41%
Memory Usage: 16.96 MB, less than 70.33%
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
    def minimumJumps(self, forbidden: List[int], a: int, b: int, x: int) -> int:
        q, visited, limit, step = deque([(0, 1)]), defaultdict(int), max(x, max(forbidden)) + b, 0
        visited[(0, 0)] = visited[(0, 1)] = 1
        for i in forbidden:
            for j in range(2):
                visited[(i, j)] = 1
        while q:
            sz = len(q)
            for _ in range(sz):
                cur_pos, prev_dir = q.popleft()
                if cur_pos == x:
                    return step
                if cur_pos <= limit and visited[(cur_pos + a, 1)] == 0:
                    q.append((cur_pos + a, 1))
                    visited[(cur_pos + a, 1)] = 1
                if prev_dir == 1 and cur_pos - b >= 0 and visited[(cur_pos - b, 0)] == 0:
                    q.append((cur_pos - b, 0))
                    visited[(cur_pos - b, 0)] = 1
            step += 1

        return -1


if __name__ == "__main__":
    s = Solution()
