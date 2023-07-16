"""
Source: https://rb.gy/7zwjy
Date: 2023/7/15
Skill:
Ref:
Runtime: 2252 ms, faster than 64.42%
Memory Usage: 52.9 MB, less than 17.31%
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
    def gcdSort(self, nums: List[int]) -> bool:
        father = [i for i in range(max(nums) + 1)]
        def find_father(x):
            if father[x] != x:
                father[x] = find_father(father[x])
            return father[x]

        def union(x, y):
            father_x, father_y = find_father(x), find_father(y)
            if father_x != father_y:
                father[father_x] = father_y

        def find_all_prime(n):
            arrs, prime = [0 for i in range(n+1)], []
            for i in range(2, math.isqrt(n)+1):
                if arrs[i] == 0:
                    num = i * 2
                    while num <= n:
                        arrs[num] = 1
                        num += i

            for i in range(2, n+1):
                if arrs[i] == 0:
                    prime.append(i)
            return prime

        primes, sz = find_all_prime(math.isqrt(max(nums))), len(nums)
        for i in range(sz):
            num = nums[i]
            for prime in primes:
                if num % prime == 0:
                    union(nums[i], prime)
                    while num % prime == 0:
                        num //= prime
            if num > 1:
                union(nums[i], num)

        sorted_nums = sorted(nums)
        for i in range(sz):
            if find_father(nums[i]) != find_father(sorted_nums[i]):
                return False
        return True


if __name__ == "__main__":
    s = Solution()

