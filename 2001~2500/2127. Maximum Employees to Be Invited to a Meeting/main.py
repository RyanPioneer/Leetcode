"""
Source: https://rb.gy/lnwjh
Date: 2023/8/8
Skill:
Ref:
Runtime: 1409 ms, faster than 93.60%
Memory Usage: 43.52 MB, less than 100.00%
Time complexity:
Space complexity:
Constraints:
    2 <= n <= 10 ** 5
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def maximumInvitations(self, favorite: List[int]) -> int:
        sz, res = len(favorite), 0
        visited = [-1 for _ in range(sz)]
        for i in range(sz):
            if visited[i] != -1:
                continue
            visited[i] = i
            num, id2order, id = 1, defaultdict(int), i
            id2order[id] = num
            while True:
                next = favorite[id]
                if visited[next] != -1:
                    if visited[next] == i:
                        if favorite[next] == id:
                            res = max(res, num)
                        else:
                            res = max(res, id2order[id] - id2order[next] + 1)
                    break
                num += 1
                id = next
                id2order[id], visited[id] = num, i

        return res


if __name__ == "__main__":
    s = Solution()
    favorite = [1, 0, 0, 2, 1, 4, 7, 8, 9, 6, 7, 10, 8]
    res = s.maximumInvitations(favorite)
    print(res)
