"""
Source: https://rb.gy/jmhx8
Date: 2023/8/15
Skill:
Ref:
Runtime: 287 ms, faster than 86.14%
Memory Usage: 17.72 MB, less than 14.46%
Time complexity:
Space complexity:
Constraints:
    1 <= arr.length <= 1000
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        res, mod, num_set, sz = 0, 10 ** 9 + 7, set(arr), len(arr)
        product, num2idx = [[] for _ in range(sz)], defaultdict(int)
        arr.sort()
        for i in range(sz):
            num2idx[arr[i]] = i
        for i in range(sz - 1, -1, -1):
            for j in range(i - 1, -1, -1):
                if arr[i] % arr[j] == 0 and arr[i] // arr[j] in num_set:
                    if arr[i] // arr[j] > arr[j]:
                        break
                    product[i].append([num2idx[arr[i] // arr[j]], j])

        dp = [-1 for _ in range(sz)]

        def helper(idx):
            if dp[idx] != -1:
                return dp[idx]
            cnt = 1
            for i in range(len(product[idx])):
                if product[idx][i][0] != product[idx][i][1]:
                    cnt += 2 * helper(product[idx][i][0]) * helper(product[idx][i][1])
                else:
                    cnt += helper(product[idx][i][0]) * helper(product[idx][i][1])
            dp[idx] = cnt
            return cnt

        for i in range(sz):
            res += helper(i)
        return res % mod


if __name__ == "__main__":
    s = Solution()

