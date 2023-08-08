"""
Source: https://leetcode.com/problems/split-the-array-to-make-coprime-products/
Date: 2023/8/8
Skill:
Ref:
Runtime: 6055 ms, faster than 17.47%
Memory Usage: 30.98 MB, less than 34.95%
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


class Solution:
    def findValidSplit(self, nums: List[int]) -> int:
        def find_all_prime(n):
            visited, res = [False for _ in range(n + 1)], set()
            for i in range(2, math.isqrt(n) + 1):
                if visited[i]:
                    continue
                num = i * i
                while num <= n:
                    visited[num] = True
                    num += i
            for i in range(2, n + 1):
                if not visited[i]:
                    res.add(i)
            return res

        prime_set, sz = find_all_prime(max(nums)), len(nums)
        prime_list = sorted(list(prime_set))
        left, right = defaultdict(int), defaultdict(int)
        for i in range(sz):
            num = nums[i]
            for j in range(len(prime_list)):
                prime = prime_list[j]
                if num == 1 or prime > num:
                    break
                if num % prime == 0:
                    while num % prime == 0:
                        num //= prime
                    if prime not in left:
                        left[prime] = i
                        right[prime] = i
                    else:
                        right[prime] = i
                elif prime * prime > num:
                    if num in prime_set:
                        if num not in left:
                            left[num] = i
                            right[num] = i
                        else:
                            right[num] = i
                    break

        first, last, time = [0 for _ in range(sz)], [0 for _ in range(sz)], 0
        for key in left.keys():
            first[left[key]] += 1
        for key in right.keys():
            last[right[key]] += 1
        time = first[0] - last[0]
        for i in range(1, sz - 1):
            if time == 0:
                return i - 1
            time += first[i] - last[i]
        return sz - 2 if time == 0 else -1


if __name__ == "__main__":
    s = Solution()
