"""
Source: https://rb.gy/gs3gy
Date: 2023/8/1
Skill: Floyd–Warshall algorithm
Ref:
Runtime: 582 ms, faster than 66.34%
Memory Usage: 17.36 MB, less than 97.26%
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
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        dp, res, cnt = [[sys.maxsize // 3 for _ in range(n)] for _ in range(n)], 0, n
        for edge in edges:
            dp[edge[0]][edge[1]] = dp[edge[1]][edge[0]] = edge[2]

        for i in range(n):
            for j in range(n):
                for k in range(n):
                    dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k])

        for i in range(n):
            num = 0
            for j in range(n):
                if j != i and dp[i][j] <= distanceThreshold:
                    num += 1
            if num <= cnt:
                cnt = num
                res = i

        return res


if __name__ == "__main__":
    s = Solution()
