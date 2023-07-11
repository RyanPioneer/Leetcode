"""
Source: https://rb.gy/137x1
Date: 2023/7/11
Skill:
Ref:
Runtime: 581 ms, faster than 97.37%
Memory Usage: 29.6 MB, less than 82.44%
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
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        cur_sum, sz, res = 0, len(arr), 0
        for i in range(k):
            cur_sum += arr[i]
        res = 1 if cur_sum >= k * threshold else 0
        for i in range(k, sz):
            cur_sum -= arr[i-k]
            cur_sum += arr[i]
            if cur_sum >= k * threshold:
                res += 1
        return res


if __name__ == "__main__":
    s = Solution()
