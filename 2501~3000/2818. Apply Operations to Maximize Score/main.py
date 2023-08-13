"""
Source: https://rb.gy/symgh
Date: 2023/8/13
Skill:
Ref:
Runtime:  ms, faster than %
Memory Usage:  MB, less than %
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
    def maximumScore(self, nums: List[int], k: int) -> int:
        def eratosthenes(num):
            primes, visited = [], [0 for _ in range(num + 1)]
            for i in range(2, math.isqrt(num) + 1):
                if visited[i]:
                    continue
                j = i * i
                while j <= num:
                    visited[j] = 1
                    j += i
            for i in range(2, num + 1):
                if not visited[i]:
                    primes.append(i)
            return primes

        prime_list, prime_score, mod, sz, res = eratosthenes(max(nums)), [], 10 ** 9 + 7, len(nums), 1
        for i in range(sz):
            cnt, cur_num = 0, nums[i]
            for prime in prime_list:
                if cur_num == 1:
                    break
                if cur_num % prime == 0:
                    cnt += 1
                    while cur_num % prime == 0:
                        cur_num //= prime
            prime_score.append(cnt)

        prime_score.append(sys.maxsize)
        smaller_after, stack = [0 for _ in range(sz)], [sz]
        for i in range(sz - 1, -1, -1):
            while stack and prime_score[stack[-1]] <= prime_score[i]:
                stack.pop()
            smaller_after[i] = stack[-1] - i - 1
            stack.append(i)

        num_list, idx = [[nums[i], i] for i in range(sz)], 0
        num_list.sort(reverse=True)
        while k > 0 and idx < sz:
            num, cnt = num_list[idx][0], smaller_after[num_list[idx][1]] + 1
            for i in range(min(k, cnt)):
                res *= num
            k -= min(k, cnt)
            idx += 1
        return res % mod


if __name__ == "__main__":
    s = Solution()
    nums, k = [19, 12, 14, 6, 10, 18], 3
    res = s.maximumScore(nums, k)
    print(res)
