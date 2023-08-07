"""
Source: https://rb.gy/mp9ep
Date: 2023/8/7
Skill:
Ref:
Runtime: 9486 ms, faster than 5.19%
Memory Usage: 34.81 MB, less than 64.94%
Time complexity:
Space complexity:
Constraints:
    1 <= k, minLength <= s.length <= 1000
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def beautifulPartitions(self, s: str, k: int, minLength: int) -> int:
        minLength = max(minLength, 2)
        mod, prime, sz = 10 ** 9 + 7, [2, 3, 5, 7], len(s)
        prime_set = set(prime)
        if int(s[0]) not in prime_set or int(s[-1]) in prime_set:
            return 0
        memo = defaultdict(int)

        def dfs(idx, num):
            if idx == sz or num == 0:
                if idx == sz and num == 0:
                    return 1
                else:
                    return 0
            if num == 1:
                return 1
            if sz - idx < minLength * num:
                return 0
            # print(idx, num)
            if int(s[idx]) not in prime_set:
                return 0
            if (idx, num) in memo:
                return memo[(idx, num)]
            total = 0
            for i in range(idx + minLength - 1, sz - minLength * (num - 1)):
                if int(s[i]) not in prime_set and int(s[i + 1]) in prime_set:
                    total += dfs(i + 1, num - 1)
            memo[(idx, num)] = total
            return total

        return dfs(0, k) % mod


if __name__ == "__main__":
    s = Solution()
    string, k, minLength = "23542185131", 3, 2
    res = s.beautifulPartitions(string, k, minLength)
    print(res)
