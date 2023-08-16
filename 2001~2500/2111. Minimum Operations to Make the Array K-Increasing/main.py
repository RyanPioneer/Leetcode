"""
Source: https://rb.gy/dh5l1
Date: 2023/8/16
Skill:
Ref:
Runtime: 993 ms, faster than 79.31%
Memory Usage: 30.29 MB, less than 96.55%
Time complexity:
Space complexity:
Constraints:
    1 <= arr.length <= 10 ** 5
    1 <= arr[i], k <= arr.length
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def kIncreasing(self, arr: List[int], k: int) -> int:
        res, sz = len(arr), len(arr)
        for i in range(k):
            start = i
            dp = [sys.maxsize for _ in range(sz // k + 2)]
            dp[0], maxlen = -sys.maxsize, 0
            while start < sz:
                if arr[start] >= dp[maxlen]:
                    maxlen += 1
                    dp[maxlen] = arr[start]
                else:
                    pos = bisect_right(dp, arr[start])
                    dp[pos] = arr[start]
                start += k
            res -= maxlen
        return res


if __name__ == "__main__":
    s = Solution()
    arr, k = [4, 1, 5, 2, 6, 2], 3
    res = s.kIncreasing(arr, k)
    print(res)
