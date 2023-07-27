"""
Source: https://rb.gy/4r4zw
Date: 2023/7/27
Skill:
Ref:
Runtime: 781 ms, faster than 92.09%
Memory Usage: 32.36 MB, less than 17.72%
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
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        players.sort(reverse=True)
        trainers.sort(reverse=True)
        sz1, sz2, res, idx = len(players), len(trainers), 0, 0
        for i in range(sz2):
            while idx < sz1 and players[idx] > trainers[i]:
                idx += 1
            if idx == sz1:
                break
            res += 1
            idx += 1
        return res


if __name__ == "__main__":
    s = Solution()
