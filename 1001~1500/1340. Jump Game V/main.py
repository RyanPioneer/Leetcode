"""
Source: https://leetcode.com/problems/jump-game-v/
Date: 2023/3/5
Skill:
Runtime: 786 ms, faster than 33.64%
Memory Usage: 15.7 MB, less than 67.58%
Time complexity:
Space complexity:
Constraints:
    1 <= arr.length <= 5 * 10^4
"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools
from sortedcontainers import SortedList


class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        dp, sz, res = [0 for _ in range(len(arr))], len(arr), 0

        def dfs(idx):
            if dp[idx] != 0:
                return dp[idx]
            dp[idx] = 1
            for i in range(1, d+1):
                if idx + i == sz or arr[idx] <= arr[idx + i]:
                    break
                dp[idx] = max(dp[idx], dfs(idx + i) + 1)

            for i in range(1, d+1):
                if idx - i < 0 or arr[idx] <= arr[idx - i]:
                    break
                dp[idx] = max(dp[idx], dfs(idx - i) + 1)

            return dp[idx]

        for i in range(sz):
            res = max(res, dfs(i))

        return res


if __name__ == "__main__":
    s = Solution()
