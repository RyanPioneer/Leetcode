"""
Source: https://leetcode.com/problems/super-ugly-number/
Date: 2023/4/16
Skill:
Ref:
Runtime: 494 ms, faster than 83.42%
Memory Usage: 17.7 MB, less than 95.8%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        sz, res, pq = len(primes), [1], []
        heapify(pq)
        p = [0 for _ in range(sz)]
        for i in range(sz):
            heappush(pq, (primes[i] * res[p[i]], i))

        for _ in range(n - 1):
            cur_min = pq[0][0]
            res.append(cur_min)
            while pq and pq[0][0] == cur_min:
                _, idx = heappop(pq)
                p[idx] += 1
                heappush(pq, (primes[idx] * res[p[idx]], idx))

        return res[-1]


if __name__ == "__main__":
    s = Solution()
