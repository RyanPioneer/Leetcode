"""
Source: https://rb.gy/7fju6
Date: 2023/8/1
Skill:
Ref:
Runtime: 33 ms, faster than 98.95%
Memory Usage: 16.33 MB, less than 54.07%
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
    def getPermutation(self, n: int, k: int) -> str:
        def get_permutation_num(digit_num):
            num = 1
            for i in range(2, digit_num + 1):
                num *= i
            return num

        res, visited = "", [0 for _ in range(n)]
        for i in range(n):
            per_num = get_permutation_num(n - i - 1)
            for j in range(n):
                if visited[j]:
                    continue
                if per_num < k:
                    k -= per_num
                else:
                    visited[j] = 1
                    res += str(j + 1)
                    break

        return res


if __name__ == "__main__":
    s = Solution()
    n, k = 3, 3
    res = s.getPermutation(n, k)
