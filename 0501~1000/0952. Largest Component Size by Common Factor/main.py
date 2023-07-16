"""
Source: https://rb.gy/8i088
Date: 2023/7/15
Skill:
Ref:
Runtime: 1367 ms, faster than 88.83%
Memory Usage: 127.06 MB, less than 5.85%
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
    def largestComponentSize(self, nums: List[int]) -> int:
        def find_all_primes(n):
            arrs, primes = [0 for _ in range(n+1)], []
            for i in range(2, math.isqrt(n) + 1):
                if arrs[i] == 0:
                    num = i * 2
                    while num <= n:
                        arrs[num] = 1
                        num += i

            for i in range(2, n+1):
                if arrs[i] == 0:
                    primes.append(i)
            return primes

        father, sz = [i for i in range(max(nums) + 1)], len(nums)

        def find_father(x):
            if father[x] != x:
                father[x] = find_father(father[x])
            return father[x]

        def union(x, y):
            father_x, father_y = find_father(x), find_father(y)
            if father_x != father_y:
                father[father_x] = father_y

        primes = find_all_primes(math.isqrt(max(nums)))
        for i in range(sz):
            num = nums[i]
            for prime in primes:
                if num % prime == 0:
                    union(nums[i], prime)
                    while num % prime == 0:
                        num = num // prime
            if num > 1:
                union(nums[i], num)

        return max(Counter(find_father(num) for num in nums).values())


if __name__ == "__main__":
    s = Solution()

