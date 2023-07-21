"""
Source: https://rb.gy/paz2v
Date: 2023/7/21
Skill: DFS + memoization
Ref:
Runtime: 1510 ms, faster than 5.00%
Memory Usage: 43.41 MB, less than 71.36%
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
    def minimizeConcatenatedLength(self, words: List[str]) -> int:
        sz = len(words)
        memo = [[[-1 for _ in range(26)] for _ in range(26)] for _ in range(sz)]

        def dfs(start, end, idx):
            if idx == sz:
                return 0
            if memo[idx][ord(start) - ord("a")][ord(end) - ord("a")] != -1:
                return memo[idx][ord(start) - ord("a")][ord(end) - ord("a")]
            head, tail = words[idx][0], words[idx][-1]
            length1 = dfs(head, end, idx + 1)
            if tail == start:
                length1 -= 1
            length2 = dfs(start, tail, idx + 1)
            if head == end:
                length2 -= 1
            memo[idx][ord(start) - ord("a")][ord(end) - ord("a")] = min(length1, length2) + len(words[idx])
            return memo[idx][ord(start) - ord("a")][ord(end) - ord("a")]

        return len(words[0]) + dfs(words[0][0], words[0][-1], 1)


if __name__ == "__main__":
    s = Solution()
