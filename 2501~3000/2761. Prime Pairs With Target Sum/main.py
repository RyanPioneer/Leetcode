"""
Source: https://rb.gy/olv8h
Date: 2023/7/17
Skill:
Ref:
Runtime: 7864 ms, faster than 14.20%
Memory Usage: 30.91 MB, less than 81.14%
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
    def findPrimePairs(self, n: int) -> List[List[int]]:
        def get_all_primes(x):
            visited, res = [0 for _ in range(x+1)], []
            for i in range(2, math.isqrt(x) + 1):
                if not visited[i]:
                    y = i*i
                    while y <= x:
                        visited[y] = 1
                        y += i
            for i in range(2, x+1):
                if not visited[i]:
                    res.append(i)
            return res

        if n <= 3:
            return []
        primes, res = get_all_primes(n), []
        prime_set = set(primes)
        if n & 1 == 1:
            if 2 in prime_set and n-2 in prime_set:
                return [[2, n-2]]
            else:
                return []

        for prime in primes:
            if prime * 2 > n:
                break
            if n - prime in prime_set:
                res.append([prime, n - prime])

        return res


if __name__ == "__main__":
    s = Solution()

