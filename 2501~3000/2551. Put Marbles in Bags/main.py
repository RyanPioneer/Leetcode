"""
Source: https://leetcode.com/problems/put-marbles-in-bags/
Date: 2023/2/17
Skill:
Runtime: 817 ms, faster than 42.58%
Memory Usage: 27.8 MB, less than 72.12%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:
        maximum, minimum, sz, arr = 0, 0, len(weights), []
        for i in range(sz-1):
            arr.append(weights[i]+weights[i+1])

        arr.sort()
        for i in range(k-1):
            maximum += arr[sz-2-i]
            minimum += arr[i]

        return maximum - minimum


if __name__ == "__main__":
    s = Solution