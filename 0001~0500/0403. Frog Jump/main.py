"""
Source: https://leetcode.com/problems/frog-jump/
Date: 2023/4/19
Skill:
Ref:
Runtime: 1562 ms, faster than 28.35%
Memory Usage: 166.9 MB, less than 5.12%
Time complexity:
Space complexity:
Constraints:
    2 <= stones.length <= 2000
    stones is sorted in a strictly increasing order.
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def canCross(self, stones: List[int]) -> bool:
        sz, next_jump, pos2idx = len(stones), [-1, 0, 1], defaultdict(int)
        dp = [[-1 for _ in range(sz)] for _ in range(sz)]
        for i in range(sz):
            pos2idx[stones[i]] = i

        def back_tracking(pos, jump):
            nonlocal sz
            if pos == sz - 1:
                return True
            for i in next_jump:
                if dp[pos][jump + i] == 1:
                    return True
                if jump + i > 0 and stones[pos] + jump + i in pos2idx and dp[pos][jump + i] != 0:
                    if back_tracking(pos2idx[stones[pos] + jump + i], jump + i):
                        dp[pos][jump + i] = 1
                        return True
                    else:
                        dp[pos][jump + i] = 0

            return False

        return back_tracking(0, 0)


if __name__ == "__main__":
    s = Solution()
