"""
Source: https://rb.gy/yfbi0
Date: 2023/7/23
Skill:
Ref:
Runtime: 349 ms, faster than 92.68%
Memory Usage: 17.4 MB, less than 94.14%
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
    def openLock(self, deadends: List[str], target: str) -> int:
        if target == "0000":
            return 0
        visited, q, step = defaultdict(int), deque(["0000"]), 0
        visited["0000"] = 1
        for i in deadends:
            if i == "0000":
                return -1
            visited[i] = 1
        neighbors = {str(i): (str((i - 1) % 10), str((i + 1) % 10)) for i in range(10)}

        while q:
            sz = len(q)
            step += 1
            for _ in range(sz):
                cur_string = q.popleft()
                for i in range(4):
                    for neighbor in neighbors[cur_string[i]]:
                        new_string = cur_string[:i] + neighbor + cur_string[i+1:]
                        if new_string == target:
                            return step
                        if new_string not in visited:
                            q.append(new_string)
                            visited[new_string] = 1

        return -1


if __name__ == "__main__":
    s = Solution()
