"""
Source: https://rb.gy/co1bw
Date: 2023/8/24
Skill:
Runtime: 7913 ms, faster than 6.98%
Memory Usage: 126.37 MB, less than 6.98%
Time complexity: state的所有可能 => 5 ** 9
Space complexity:
Constraints:
    1 <= batchSize <= 9
    1 <= groups.length <= 30
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
from functools import cache


class Solution:
    def maxHappyGroups(self, batchSize: int, groups: List[int]) -> int:
        sz, cnt, state, dp = len(groups), [0 for _ in range(batchSize)], 0, defaultdict(int)
        for i in groups:
            cnt[i % batchSize] += 1
        for i in range(batchSize):
            num = 32 ** i
            state += num * cnt[i]

        def dfs(state, cur_sum, num):
            if num == sz:
                return 0
            if state in dp:
                return dp[state]
            cur_sum %= batchSize
            result = 0
            for i in range(batchSize):
                cnt = state // (32 ** i) % 32
                if cnt > 0:
                    result = max(result, dfs(state - 32 ** i, cur_sum + i, num + 1))
            if cur_sum == 0:
                result += 1
            dp[state] = result
            return result

        return dfs(state, 0, 0)


if __name__ == "__main__":
    s = Solution()
